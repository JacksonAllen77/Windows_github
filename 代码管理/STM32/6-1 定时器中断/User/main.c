#include "stm32f10x.h"  // 引入STM32标准外设库头文件
#include "Delay.h"       // 引入延迟函数库
#include "OLED.h"
#include "Encoder.h"

int16_t Num;

int main(void)
{
	OLED_Init();
	Enconder_Init();
	OLED_ShowString(1,1,"Num:");
	
	
    while(1)
    {
				Num+=Encoder_Get();
        OLED_ShowSignedNum(1,5,Num,5);
				
    }
}
