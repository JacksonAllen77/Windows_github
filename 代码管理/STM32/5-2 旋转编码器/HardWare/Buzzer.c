#include "stm32f10x.h"                  // Device header

void Buzzer_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//点亮PB12的LED，使能时钟
	GPIO_InitTypeDef  GPIO_InitStructure;//定义结构体
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;    //设置结构体参数（GPIO模式、端口、速度）[推挽输出]
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;//PB12因此选Pin_12
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//输出速度正常选50
	GPIO_Init(GPIOB,&GPIO_InitStructure);//配置端口模式
	
}

void Buzzer_On(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);//给低电平点亮

}

void Buzzer_Off(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_12);//给高电平熄灭
	
}
void Buzzer_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_12)==0)//若检测PIN1位输出为低电平，则置高电平熄灭；若输出为高电平，则置低电平点亮
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
	}
	else
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	}
}
