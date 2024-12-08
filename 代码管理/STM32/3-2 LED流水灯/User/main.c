#include "stm32f10x.h"                  // Device header
#include "delay.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//点亮PA0的LED，使能时钟
	GPIO_InitTypeDef  GPIO_InitStructure;//定义结构体
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;    //设置结构体参数（GPIO模式、端口、速度）[推挽输出]
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_All;//PA0因此选Pin_0
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//输出速度正常选50
	GPIO_Init(GPIOA,&GPIO_InitStructure);//配置端口模式
//	GPIO_SetBits(GPIOA,GPIO_Pin_0);//将13口设置为高电平(熄灭)
//	GPIO_ResetBits(GPIOA,GPIO_Pin_0);//将13口设置为低电平（点亮）
	
	while(1)
	{
		GPIO_Write(GPIOA,~0x0001);//0000 0000 0000 0001[由于低电平点亮，故取反~]
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0002);//0000 0000 0000 0010
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0004);//0000 0000 0000 0100
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0008);//0000 0000 0000 1000[由于低电平点亮，故取反~]
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0010);//0000 0000 0001 0000
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0020);//0000 0000 0010 0000
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0040);//0000 0000 0100 0000
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0080);//0000 0000 1000 0000
		Delay_ms(100);	
	}

}
