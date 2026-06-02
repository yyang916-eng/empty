#include "ti_msp_dl_config.h"                  // Device header
#include "Motor.h"
#include "PWM.h"

/**
  * 函    数：直流电机初始化
  * 参    数：无
  * 返 回 值：无
  */
// void MotorA_Init(void)
// {
// 	/*开启时钟*/
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//开启GPIOB的时钟
	
// 	GPIO_InitTypeDef GPIO_InitStructure;
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
// 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(GPIOB, &GPIO_InitStructure);					//将PB12和PB13引脚初始化为推挽输出
	
// 	PWMA_Init();												//初始化直流电机的底层PWM
// }

/**
  * 函    数：直流电机设置PWM
  * 参    数：PWM 要设置的PWM值，范围：-100~100（负数为反转）
  * 返 回 值：无
  */
// void MotorA_SetPWM(int8_t PWM)
// {
// 	if (PWM >= 0)							//如果设置正转的PWM
// 	{
// 		GPIO_ResetBits(GPIOB, GPIO_Pin_12);	//PB12置低电平
// 		GPIO_SetBits(GPIOB, GPIO_Pin_13);	//PB13置高电平
// 		PWMA_SetCompare1(PWM);				//设置PWM占空比
// 	}
// 	else									//否则，即设置反转的速度值
// 	{
// 		GPIO_SetBits(GPIOB, GPIO_Pin_12);	//PB12置高电平
// 		GPIO_ResetBits(GPIOB, GPIO_Pin_13);	//PB13置低电平
// 		PWMA_SetCompare1(-PWM);				//设置PWM占空比
// 	}
// }

// void MotorB_Init(void)
// {
// 	/*开启时钟*/
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//开启GPIOB的时钟
	
// 	GPIO_InitTypeDef GPIO_InitStructure;
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
// 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
// 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(GPIOB, &GPIO_InitStructure);					//将PB10和PB11引脚初始化为推挽输出
	
// 	PWMB_Init();												//初始化直流电机的底层PWM
// }

/**
  * 函    数：直流电机设置PWM
  * 参    数：PWM 要设置的PWM值，范围：-100~100（负数为反转）
  * 返 回 值：无
  */
// void MotorB_SetPWM(int8_t PWM)
// {
// 	if (PWM >= 0)							//如果设置正转的PWM
// 	{
// 		GPIO_ResetBits(GPIOB, GPIO_Pin_10);	//PB10置低电平
// 		GPIO_SetBits(GPIOB, GPIO_Pin_11);	//PB11置高电平
// 		PWMB_SetCompare1(PWM);				//设置PWM占空比
// 	}
// 	else									//否则，即设置反转的速度值
// 	{
// 		GPIO_SetBits(GPIOB, GPIO_Pin_10);	//PB10置高电平
// 		GPIO_ResetBits(GPIOB, GPIO_Pin_11);	//PB11置低电平
// 		PWMB_SetCompare1(-PWM);				//设置PWM占空比
// 	}
// }

// 电机A设置速度与方向 PWM范围：-100 ~ 100
void MotorA_SetPWM(int8_t PWM)
{
    if (PWM >= 0)
    {
        // 正转
        DL_GPIO_setPins(GPIO_MOTOR_PORT, GPIO_MOTOR_A_2_PIN);
        DL_GPIO_clearPins(GPIO_MOTOR_PORT, GPIO_MOTOR_A_1_PIN);
        PWM_SetDuty_CH0(PWM);
    }
    else
    {
        // 反转
        DL_GPIO_setPins(GPIO_MOTOR_PORT, GPIO_MOTOR_A_1_PIN);
        DL_GPIO_clearPins(GPIO_MOTOR_PORT, GPIO_MOTOR_A_2_PIN);
        PWM_SetDuty_CH0(-PWM);
    }
}

// 电机B设置速度与方向 PWM范围：-100 ~ 100
void MotorB_SetPWM(int8_t PWM)
{
    if (PWM >= 0)
    {
        // 正转
        DL_GPIO_setPins(GPIO_MOTOR_PORT,GPIO_MOTOR_B_2_PIN);
        DL_GPIO_clearPins(GPIO_MOTOR_PORT, GPIO_MOTOR_B_1_PIN);
        PWM_SetDuty_CH1(PWM);
    }
    else
    {
        // 反转
        DL_GPIO_setPins(GPIO_MOTOR_PORT, GPIO_MOTOR_B_1_PIN);
        DL_GPIO_clearPins(GPIO_MOTOR_PORT, GPIO_MOTOR_B_2_PIN);
        PWM_SetDuty_CH1(-PWM);
    }
}