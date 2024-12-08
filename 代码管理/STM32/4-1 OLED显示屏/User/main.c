#include "stm32f10x.h"  // 引入STM32标准外设库头文件
#include "Delay.h"       // 引入延迟函数库
#include "OLED.h"

int main(void)
{
	OLED_Init();
	OLED_ShowChar(1,1,'I');//在第1行第1列显示字符[总4行16列]
	OLED_ShowString(1,4,"Love You");//显示字符串
	//	OLED_Clear();//清屏操作【可根据需要清除上方显示代码】
	OLED_ShowNum(2,1,12345,5);//显示数字【多了补0，少了切】
	OLED_ShowSignedNum(2,7,-78,2);//显示有符号数字
	OLED_ShowHexNum(3,1,0xCA58,4);//显示16进制数
	OLED_ShowBinNum(4,1,0xCA58,16);//显示2进制数
	
	
    while(1)
    {
        
    }
}
