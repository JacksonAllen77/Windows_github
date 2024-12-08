#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//点亮PB12的LED，使能时钟
	GPIO_InitTypeDef  GPIO_InitStructure;//定义结构体
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;    //设置结构体参数（GPIO模式、端口、速度）[上拉输入模式]
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_11;//PB1和PB11因此选Pin_1|11
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//输出速度正常选50
	GPIO_Init(GPIOB,&GPIO_InitStructure);//配置端口模式
	
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum=0;
	if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
	{
		Delay_ms(20);//对按键被按下进行延时消抖处理
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
		Delay_ms(20);//对按键被松开进行延时消抖处理
		KeyNum=1;
	}
	
	if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)
	{
		Delay_ms(20);//对按键被按下进行延时消抖处理
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)
		Delay_ms(20);//对按键被松开进行延时消抖处理
		KeyNum=2;
	}
	return 	KeyNum;
}
