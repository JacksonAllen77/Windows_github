#include "stm32f10x.h"                  // Device header
#include "delay.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//点亮PA0的LED，使能时钟
	GPIO_InitTypeDef  GPIO_InitStructure;//定义结构体
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;    //设置结构体参数（GPIO模式、端口、速度）[推挽输出]
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;//PA0因此选Pin_0
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//输出速度正常选50
	GPIO_Init(GPIOA,&GPIO_InitStructure);//配置端口模式
//	GPIO_SetBits(GPIOA,GPIO_Pin_0);//将13口设置为高电平(熄灭)
//	GPIO_ResetBits(GPIOA,GPIO_Pin_0);//将13口设置为低电平（点亮）
	
	while(1)
	{
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);//通过切换第三个参数的Bit_SET和Bit_RESET点亮和熄灭LED灯
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);//通过切换第三个参数的Bit_SET和Bit_RESET点亮和熄灭LED灯
		Delay_ms(100);
	}

}
