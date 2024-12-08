#include "stm32f10x.h"  // 引入STM32标准外设库头文件
#include "Delay.h"       // 引入延迟函数库
#include "LED.h"         // 引入LED控制函数库
#include "Buzzer.h"      // 引入蜂鸣器控制函数库
#include "LightSensor.h" // 引入光敏电阻控制函数库

int main(void)
{
    Buzzer_Init();          // 初始化蜂鸣器
    LightSensor_Init();     // 初始化光敏电阻
	
    while(1)
    {
        if(LightSensor_Get()==1)  // 光线暗时蜂鸣器响
        {
           Buzzer_On();           // 打开蜂鸣器
        }
        else
        {
						Buzzer_Off();// 关闭蜂鸣器
        }
    }
}
