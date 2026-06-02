#include "ti_msp_dl_config.h"                  // Device header
volatile uint8_t L1, L2, L3, L4, L5, L6, L7;                
volatile uint8_t L;

void xunji_Init(void)
{

	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	
	

	// GPIO_InitTypeDef GPIO_InitStructure;
	// //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	// GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_4| GPIO_Pin_5;
	// GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	// GPIO_Init(GPIOB, &GPIO_InitStructure);					
	
	// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3| GPIO_Pin_4| GPIO_Pin_5;
	// GPIO_Init(GPIOA, &GPIO_InitStructure);	

	// 开启 GPIOA、GPIOB 时钟
    //DL_SYSCTL_enablePeripheral(DL_SYSCTL_PERIPH_GPIOA);
    //DL_SYSCTL_enablePeripheral(DL_SYSCTL_PERIPH_GPIOB);

    // ====================== 配置上拉输入 ======================
    // PA2, PA3, PA4, PA5
}

void f1(void)
{

	//PB24
    uint32_t portValue1 = DL_GPIO_readPins(GPIO_XUNJI_PIN_0_PORT, GPIO_XUNJI_PIN_0_PIN);

    // 正确判断引脚电平
    if( (portValue1 & GPIO_XUNJI_PIN_0_PIN) != 0 )
    {
        L1 = 1;   // 高电平
    }
    else
    {
        L1 = 0;   // 低电平
    }

    uint32_t portValue2 = DL_GPIO_readPins(GPIO_XUNJI_PIN_1_PORT, GPIO_XUNJI_PIN_1_PIN);

    //PB15
    if( (portValue2 & GPIO_XUNJI_PIN_1_PIN) != 0 )
    {
        L2 = 1;   // 高电平
    }
    else
    {
        L2 = 0;   // 低电平
    }

	uint32_t portValue3 = DL_GPIO_readPins(GPIO_XUNJI_PIN_2_PORT, GPIO_XUNJI_PIN_2_PIN);

    //PB16
    if( (portValue3 & GPIO_XUNJI_PIN_2_PIN) != 0 )
    {
        L3 = 1;   // 高电平
    }
    else
    {
        L3 = 0;   // 低电平
    }

	uint32_t portValue4 = DL_GPIO_readPins(GPIO_XUNJI_PIN_3_PORT, GPIO_XUNJI_PIN_3_PIN);

    //PB17
    if( (portValue4 & GPIO_XUNJI_PIN_3_PIN) != 0 )
    {
        L4 = 1;   // 高电平
    }
    else
    {
        L4 = 0;   // 低电平
    }

	uint32_t portValue5 = DL_GPIO_readPins(GPIO_XUNJI_PIN_4_PORT, GPIO_XUNJI_PIN_4_PIN);

    //PA18
    if( (portValue5 & GPIO_XUNJI_PIN_4_PIN) != 0 )
    {
        L5 = 1;   // 高电平
    }
    else
    {
        L5 = 0;   // 低电平
    }

	uint32_t portValue6 = DL_GPIO_readPins(GPIO_XUNJI_PIN_5_PORT, GPIO_XUNJI_PIN_5_PIN);

    //PB18
    if( (portValue6 & GPIO_XUNJI_PIN_5_PIN) != 0 )
    {
        L6 = 1;   // 高电平
    }
    else
    {
        L6 = 0;   // 低电平
    }

	uint32_t portValue7 = DL_GPIO_readPins(GPIO_XUNJI_PIN_6_PORT, GPIO_XUNJI_PIN_6_PIN);

    //PA22
    if( (portValue7 & GPIO_XUNJI_PIN_6_PIN) != 0 )
    {
        L7 = 1;   // 高电平
    }
    else
    {
        L7 = 0;   // 低电平
    }

	
	// L1=GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2);
	// L2=GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3);
	// L3=GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4);
	// L4=GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5);
	// L5=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1);
	// L6=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4);
	// L7=GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5);
	
	// L1 = DL_GPIO_readPins(GPIO_XUNJI_PIN_0_PORT, GPIO_XUNJI_PIN_0_PIN);
    // L2 = DL_GPIO_readPins(GPIO_XUNJI_PIN_1_PORT, GPIO_XUNJI_PIN_1_PIN);
    // L3 = DL_GPIO_readPins(GPIO_XUNJI_PIN_2_PORT, GPIO_XUNJI_PIN_2_PIN);
    // L4 = DL_GPIO_readPins(GPIO_XUNJI_PIN_3_PORT, GPIO_XUNJI_PIN_3_PIN);
    // L5 = DL_GPIO_readPins(GPIO_XUNJI_PIN_4_PORT, GPIO_XUNJI_PIN_4_PIN);
    // L6 = DL_GPIO_readPins(GPIO_XUNJI_PIN_5_PORT, GPIO_XUNJI_PIN_5_PIN);
    // L7 = DL_GPIO_readPins(GPIO_XUNJI_PIN_6_PORT, GPIO_XUNJI_PIN_6_PIN);

    // // 把读取值转成 0/1（和 STM32 行为一致）
    // L1 = (L1 != 0) ? 1 : 0;
    // L2 = (L2 != 0) ? 1 : 0;
    // L3 = (L3 != 0) ? 1 : 0;
    // L4 = (L4 != 0) ? 1 : 0;
    // L5 = (L5 != 0) ? 1 : 0;
    // L6 = (L6 != 0) ? 1 : 0;
    // L7 = (L7 != 0) ? 1 : 0;

}

