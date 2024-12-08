#include <REGX52.H>
#include <INTRINS.H>  // 延时模块所需的头文件

void Delay1ms(unsigned int xms)		//@12.000MHz---通过传入参数的方式实现任意时间延时
{
	unsigned char i, j;
	while(xms)
	{
		i = 2;
		j = 239;
	do
	{
		while (--j);
	} while (--i);
		xms--;
	}
}


	void main()//主函数传入延时时间
	{
		while(1)
		{
			P2 = 0xFE;  // 点亮 D1(二进制1111 1110)
			Delay1ms(300);
			P2 = 0xFD;  // 点亮 D2(二进制1111 1101)
			Delay1ms(300);
			P2 = 0xFB;  // 点亮 D3(二进制1111 1011)
			Delay1ms(300);
			P2 = 0xF7;  // 点亮 D4(二进制1111 0111)
			Delay1ms(300);
			P2 = 0xEF;  // 点亮 D5(二进制1110 1111)
			Delay1ms(300);
			P2 = 0xDF;  // 点亮 D6(二进制1101 1111)
			Delay1ms(300);
			P2 = 0xBF;  // 点亮 D7(二进制1011 1111)
			Delay1ms(300);
			P2 = 0x7F;  // 点亮 D8(二进制0111 1111)
			Delay1ms(300);
		}
	}