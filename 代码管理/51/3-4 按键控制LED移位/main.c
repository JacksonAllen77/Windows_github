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
    unsigned char LEDNum = 0;
	P2=~(0X01);//初始上电，第一个灯点亮
    while(1)
    {
        if(P3_3 == 0) // 检测按键是否按下
        {
            Delay(20); // 延时消除抖动
            while(P3_3 == 0) // 等待按键松开
            {
                Delay(20); // 延时消除抖动
            }
            LEDNum++;
            if (LEDNum >= 8)
            {
                LEDNum = 0;
            }
            P2 = ~(0x01 << LEDNum); // 控制LED灯流水点亮
        }
				if(P3_2 == 0) // 检测按键是否按下
        {
            Delay(20); // 延时消除抖动
            while(P3_2 == 0) // 等待按键松开
            {
                Delay(20); // 延时消除抖动
            }
						if (LEDNum == 0)
            {
                LEDNum = 7;
            }
						else
						{
							LEDNum--;
						}
            P2 = ~(0x01 << LEDNum); // 控制LED灯流水点亮
        }
				
    }
}
