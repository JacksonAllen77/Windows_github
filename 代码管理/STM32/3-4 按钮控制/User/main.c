#include "stm32f10x.h"  // 引入STM32标准外设库头文件
#include "Delay.h"       // 引入延迟函数库
#include "LED.h"         // 引入LED控制函数库
#include "Key.h"         // 引入按键控制函数库

uint8_t KeyNum;//定义全局变量，用于接收按键信息

int main(void)
{
    LED_Init();  // 调用LED初始化函数，设置LED相关的GPIO和定时器等
		Key_Init();	// 调用Key初始化函数
	
    while(1)
    {
			KeyNum=Key_GetNum();//读取输入数据
			if (KeyNum==1)
			{
				LED1_On();
				LED2_Off();
			}
			if (KeyNum==2)
			{
				LED2_On();
				LED1_Off();
			}
    }
}
