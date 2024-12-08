#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//点亮PB12的LED，使能时钟
	GPIO_InitTypeDef  GPIO_InitStructure;//定义结构体
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;    //设置结构体参数（GPIO模式、端口、速度）[推挽输出]
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2;//PB12因此选Pin_12
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//输出速度正常选50
	GPIO_Init(GPIOA,&GPIO_InitStructure);//配置端口模式
	
//	GPIO_SetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_2);//LED熄灭
	GPIO_ResetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_2);//LED点亮

}

void LED1_On(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);//给低电平点亮

}

void LED1_Off(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1);//给高电平熄灭
	
}
void LED1_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==0)//若检测PIN1位输出为低电平，则置高电平熄灭；若输出为高电平，则置低电平点亮
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_1);
	}
	else
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	}
}
void LED2_On(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);

}

void LED2_Off(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
	
}
void LED2_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)==0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_2);
	}
	else
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	}
}