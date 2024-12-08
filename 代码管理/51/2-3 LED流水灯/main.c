#include <REGX52.H>
#include <INTRINS.H>  // 延时模块所需的头文件

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
		// 从 D1 到 D8 依次点亮
		P2 = 0xFE;  // 点亮 D1(二进制1111 1110)
		Delay500ms();
		P2 = 0xFD;  // 点亮 D2(二进制1111 1101)
		Delay500ms();
		P2 = 0xFB;  // 点亮 D3(二进制1111 1011)
		Delay500ms();
		P2 = 0xF7;  // 点亮 D4(二进制1111 0111)
		Delay500ms();
		P2 = 0xEF;  // 点亮 D5(二进制1110 1111)
		Delay500ms();
		P2 = 0xDF;  // 点亮 D6(二进制1101 1111)
		Delay500ms();
		P2 = 0xBF;  // 点亮 D7(二进制1011 1111)
		Delay500ms();
		P2 = 0x7F;  // 点亮 D8(二进制0111 1111)
		Delay500ms();
	}
}
