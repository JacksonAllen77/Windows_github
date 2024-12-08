#include "stm32f10x.h"                  // 包含STM32F10x标准外设库头文件，用于操作寄存器和外设

int main(void)
{
    // 使能 GPIOC 的时钟，外设时钟由 RCC 模块控制
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); 

    GPIO_InitTypeDef GPIO_InitStructure; // 定义 GPIO 初始化结构体，用于配置 GPIO 参数

    // 配置 GPIO 模式为推挽输出模式 (Output Push-Pull)
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;

    // 选择 GPIOC 的第 13 号引脚 (PC13)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;

    // 设置 GPIO 引脚的速度为 50MHz，决定引脚输出变化的响应速度
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    // 初始化 GPIOC，根据配置结构体 GPIO_InitStructure 设置相关引脚
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    // 设置 PC13 引脚为低电平（通常用于点亮板载 LED）
    GPIO_ResetBits(GPIOC, GPIO_Pin_13);

    while (1) // 无限循环，嵌入式程序常用结构，用于保持程序运行
    {
        // 在这里可以添加其他需要的功能逻辑
    }
}
