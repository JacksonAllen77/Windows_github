#include "stm32f10x.h"                  // Device header

void Timer_Init(void)
{
	//1.RCC开启时钟
	//2.选择时基单元的时钟源【对于定时中断——内部时钟源】
	//3.配置时基单元
	//4.配置输出中断控制
	//5.配置NVIC，并分配优先级


}
//编写定时器中断函数
