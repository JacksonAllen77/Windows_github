#include "stm32f10x.h"  // 引入STM32标准外设库头文件
#include "Delay.h"       // 引入延迟函数库
#include "OLED.h"
#include "CountSensor.h"

int main(void)
{
	OLED_Init();
	CountSensor_Init();
	OLED_ShowString(1,1,"Count:");
	
	
    while(1)
    {
        OLED_ShowNum(1,7,CountSensor_Get(),5);
    }
}
