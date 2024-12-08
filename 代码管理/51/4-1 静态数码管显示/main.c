//数码管位置封装函数和数字数组，通过传入参数实现在某位置显示某个数
#include <REGX52.H>

void Nixie(unsigned char loc,unsigned char num)
{
	unsigned int NumberTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x00};
	switch(loc)
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;//LED8对应Y7（111）
		case 2:P2_4=1;P2_3=1;P2_2=0;break;//LED7对应Y6（110）
		case 3:P2_4=1;P2_3=0;P2_2=1;break;//LED6对应Y5（101）
		case 4:P2_4=1;P2_3=0;P2_2=0;break;//LED5对应Y4（100）
		case 5:P2_4=0;P2_3=1;P2_2=1;break;//LED4对应Y3（011）
		case 6:P2_4=0;P2_3=1;P2_2=0;break;//LED3对应Y2（010）
		case 7:P2_4=0;P2_3=0;P2_2=1;break;//LED2对应Y1（001）
		case 8:P2_4=0;P2_3=0;P2_2=0;break;//LED1对应Y0（000）
	}
		P0=NumberTable[num];
	
}

void main()
{
	Nixie(1,5);
	while(1)
	{
		
	}
}
