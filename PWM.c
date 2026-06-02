#include "ti_msp_dl_config.h"
#include "PWM.h"

// PA12接1P  PA13接2P
// PB2接1N1 PB3接1N2  PB7接2N1 PB6接2N2

void PWM_Init(void)
{
    DL_TimerG_startCounter(PWM_0_INST);
}

// 设置通道0占空比，输入范围：0~100（百分比）
void PWM_SetDuty_CH0(uint16_t duty_percent)
{
    uint16_t compare = (uint32_t)duty_percent * 3200 / 100;  // 映射到 0~3200
    if (compare > 3200) compare = 3200;
    DL_TimerG_setCaptureCompareValue(PWM_0_INST, compare, DL_TIMER_CC_0_INDEX);
}

// 设置通道1占空比，输入范围：0~100（百分比）
void PWM_SetDuty_CH1(uint16_t duty_percent)
{
    uint16_t compare = (uint32_t)duty_percent * 3200 / 100;
    if (compare > 3200) compare = 3200;
    DL_TimerG_setCaptureCompareValue(PWM_0_INST, compare, DL_TIMER_CC_1_INDEX);
}
