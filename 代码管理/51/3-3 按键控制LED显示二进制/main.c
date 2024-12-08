#include <REGX52.H>
#include <INTRINS.H>  // 延时模块所需的头文件

void Delay(unsigned int xms) // 延时函数
{
    unsigned char i, j;
    while(xms--)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);
    }
}

void main()
{
		unsigned char LEDNum=0;//定义一个LED灯状态变量
    while(1)  // 无限循环
    {
       if(P3_2==0)//如果按键被按下
			 {
					Delay(20);//延时消除抖动
					while(P3_2==0);//等待按键松开
					Delay(20);//延时消除抖动
					LEDNum++;//每次按下时，变量数值+1
					P2=~LEDNum;//将LEDNum的值取反赋给P2【由于低电平点亮，所以需要取反】
			 }
    }
}
