/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ti_msp_dl_config.h"
#include <stdint.h>
#include <stdio.h>

#include "LED.h"
#include "Delay.h"
#include "Key.h"
#include "PWM.h"
#include "Motor.h"
#include "PID.h"
#include "xunji.h"

PID_t A = {
	.Kp = 0.32,
	.Ki = 0.007,
	.Kd = 0.70,
	.OutMax = 50,
	.OutMin = -50,
};

// uint8_t L1,L2,L3,L4,L5,L6,L7,L;

void TIMER_0_INST_IRQHandler(void)
{
    static uint16_t count = 0;

    // 判断并清除中断
    if (DL_TimerA_getPendingInterrupt(TIMER_0_INST) == DL_TIMER_IIDX_ZERO)
    {
        DL_TimerA_clearInterruptStatus(TIMER_0_INST,DL_TIMER_IIDX_ZERO);

        count++;
        if(count >= 40)       // 1ms ×40 = 40ms
        {
            count = 0;
            PID_Update(&A);   // 40ms 执行一次 PID
            // LED_Turn();    //测试PID是否进入中断
            
        }
    }
}

int main(void)
{
    /* 关闭总中断，防止初始化时干扰 */
    __disable_irq();

    SYSCFG_DL_init();
    PWM_Init();
    xunji_Init();
    LED_Init();
    Key_Init();

     DL_TimerA_enableInterrupt(TIMER_0_INST, DL_TIMER_IIDX_ZERO);

     NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    
    /* 开启总中断 */
    __enable_irq();
     
    while (1) {

    // //led判断  
    // f1();

    // // 调试：根据 L1 状态控制 LED
    // if (L4 == 0) {
    //     LED_OFF();   // 检测到黑线，LED 灭
    // } else {
    //     LED_ON();  // 未检测到，LED 亮
    // }

    //    //led亮灭
    //    LED_ON();
    //    Delay_ms(500);

    //    LED_OFF();
    //    Delay_ms(500);

    // // 按键扫描：主循环里循环调用，相当于1ms一次（因为循环很快）
    //     Key_Tick();

    //     // 获取按键键码
    //     uint8_t keyCode = Key_GetNum();
    //     if (keyCode == 1)
    //     {
    //         // 按键按下松手后，翻转LED状态
    //         LED_Turn();
    //     }

/* 读取循迹传感器 */
        f1();
        /* 记录最后一次偏离方向（用于全白回正） */
        if (L7 == 1)
        {
            L = 0;
        }
        if (L1 == 1)
        {
            L = 1;
        }
        if (L1 == 1 && L7 == 1)
        {
            L = 0;
        }

        /* 处理全白情况：原地旋转回正 */
        while (L4 == 0 && L5 == 0 && L6 == 0 && L7 == 0 &&
               L1 == 0 && L2 == 0 && L3 == 0)
        {
            f1();
            while (L3 == 0 && L4 == 0 && L5 == 0)
            {
                f1();
                if (L == 0)
                {
                    MotorA_SetPWM(10);
                    MotorB_SetPWM(-10);
                }
                if (L == 1)
                {
                    MotorA_SetPWM(-10);
                    MotorB_SetPWM(10);
                }
            }
        }

        /* 计算循迹偏差值 */
        A.Actual = L1*(26) + L2*(13) + L3*(8) + L4*(0) +
                   L5*(-8) + L6*(-13) + L7*(-26);

        /* 差速驱动：直行 + PID 纠偏 */
        MotorA_SetPWM(24 - A.Out);
        MotorB_SetPWM(24 + A.Out);
        
    }
 }


