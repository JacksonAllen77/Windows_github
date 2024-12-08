#include <REGX52.H>
#include <INTRINS.H>//延时模块所需的头文件

void Delay500ms()		//@12.000MHz——复制自动生成的延时模块
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 205;
	k = 187;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{	
	while(1)
	{
		P2=0xFE;//二进制1111 1110（实现D1灯亮）
		Delay500ms();//调用延时指令
		P2=0XFF;//二进制1111 1111（实现D1灯灭）
		Delay500ms();//调用延时指令
	}
	
}