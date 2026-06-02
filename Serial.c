#include "ti_msp_dl_config.h"
#include <stdio.h>
#include <stdarg.h>
#include "Serial.h"

uint8_t Serial_RxData;
uint8_t Serial_RxFlag = 0;

// 串口初始化
void Serial_Init(void)
{
    // 使能UART中断
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
}

// 发送一个字节
void Serial_SendByte(uint8_t Byte)
{
    DL_UART_transmitDataBlocking(UART_0_INST, Byte);
}

// 发送数组
void Serial_SendArray(uint8_t *Array, uint16_t Length)
{
    uint16_t i;
    for (i = 0; i < Length; i++)
    {
        Serial_SendByte(Array[i]);
    }
}

// 发送字符串
void Serial_SendString(char *String)
{
    while (*String)
    {
        Serial_SendByte(*String++);
    }
}

// 次方函数
uint32_t Serial_Pow(uint32_t X, uint32_t Y)
{
    uint32_t Result = 1;
    while (Y--)
    {
        Result *= X;
    }
    return Result;
}

// 发送数字
void Serial_SendNumber(uint32_t Number, uint8_t Length)
{
    uint8_t i;
    for (i = 0; i < Length; i++)
    {
        Serial_SendByte(Number / Serial_Pow(10, Length - i - 1) % 10 + '0');
    }
}

// 重定向 printf
int fputc(int ch, FILE *f)
{
    Serial_SendByte(ch);
    return ch;
}

// 封装 printf
void Serial_Printf(char *format, ...)
{
    char String[100];
    va_list arg;
    va_start(arg, format);
    vsprintf(String, format, arg);
    va_end(arg);
    Serial_SendString(String);
}

// 获取接收标志
uint8_t Serial_GetRxFlag(void)
{
    if (Serial_RxFlag == 1)
    {
        Serial_RxFlag = 0;
        return 1;
    }
    return 0;
}

// 获取接收数据
uint8_t Serial_GetRxData(void)
{
    return Serial_RxData;
}

// 串口接收中断函数
void UART0_INT_IRQHandler(void)
{
    // 接收中断
    if (DL_UART_getPendingInterrupt(UART_0_INST))
    {
        Serial_RxData = DL_UART_receiveData(UART_0_INST);
        Serial_RxFlag = 1;

        // 清除中断
        DL_UART_clearInterruptStatus(UART_0_INST, DL_UART_INTERRUPT_RX);
    }
}