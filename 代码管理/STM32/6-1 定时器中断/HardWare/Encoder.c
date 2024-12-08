#include "stm32f10x.h"                  // Device header


int16_t Encoder_Count;//定义一个带符号的变量
void Enconder_Init(void)
{
	//第一步：开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//配置RCC外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//配置AFIO时钟[由于EXTI、NVIC时钟常开，无需配置]
	//第二步：配置GPIO端口输入模式
	GPIO_InitTypeDef  GPIO_InitStructure;//定义GPIO结构体
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;    //设置GPIO模式[对于外部中断——浮空、上拉、下拉输入][上拉——高电平输入方式]
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;//设置GPIO端口[PB0&PB1]
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//设置GPIO输出速度
	GPIO_Init(GPIOB,&GPIO_InitStructure);//配置端口模式
	//第三步：配置AFIO
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);//由于采用PB14口
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);//由于采用PB14口
	//第四步：配置EXTI边沿触发方式【上升沿、下降沿、双边沿】&触发响应方式【中断响应、事件响应】
	EXTI_InitTypeDef  EXTI_InitStructure;//定义EXTI结构体
	EXTI_InitStructure.EXTI_Line=EXTI_Line0|EXTI_Line1;//设置中断线【由于PB0|1所以选EXTI_Line0|1】
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;//设置中断线是否开启
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;//设置中断模式还是事件模式[中断模式]
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;//设置边沿触发方式[下降沿]
	EXTI_Init(&EXTI_InitStructure);
	//第五步：配置NVIC【给中断优先级】
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//根据抢占和响应需求进行选择【分组2—2位抢占，2位响应】
	NVIC_InitTypeDef  NVIC_InitStructure;//定义NVIC结构体
	NVIC_InitStructure.NVIC_IRQChannel=EXTI0_IRQn;//指定中断通道[PB14所以选这个]
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//设置中断通道是否开启
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级【由于选分组2：取值范围0-3】
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;////设置响应优先级【由于选分组2：取值范围0-3】
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel=EXTI1_IRQn;//指定中断通道[PB14所以选这个]
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//设置中断通道是否开启
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;//设置抢占优先级【由于选分组2：取值范围0-3】
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;////设置响应优先级【由于选分组2：取值范围0-3】
	NVIC_Init(&NVIC_InitStructure);

}

void EXTI0_IRQHandler(void)//分别编写中断函数【无参无返回值】
{
	
	//中断标志位判断是否为1
	if(EXTI_GetITStatus(EXTI_Line0)==SET)
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)//判断引脚电平，如果是则为反转
		{
			Encoder_Count--;
		}
		EXTI_ClearITPendingBit(EXTI_Line0);//清除中断标志位
	}
	
}

int16_t Encoder_Get(void)//用于获取计数的函数
{
	int16_t Temp;
	Temp=Encoder_Count;
	Encoder_Count=0;
	return Temp;
}
	
void EXTI1_IRQHandler(void)//编写中断函数【无参无返回值】
{
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==0)
		{
			Encoder_Count++;
		}
	//中断标志位判断是否为1
	if(EXTI_GetITStatus(EXTI_Line1)==SET)
	{
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
	
}
