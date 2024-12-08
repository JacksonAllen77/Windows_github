#include <REGX52.H>
#include <INTRINS.H>  // 延时模块所需的头文件

void Delay(unsigned int xms)//@12.000MHz——复制的延时代码
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


void main()
{
	while(1)
	{
		if(P3_0==0)//若按键被按下
		{
			Delay(20);//延时消除抖动
			while(P3_0==0);//等待按键松开
			Delay(20);//延时消除抖动
			P2_0=~P2_0;//位取反操作，反转P2_0位的状态（亮-灭转换）
		}
	}

}
