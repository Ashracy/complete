
void delay1ms(unsigned int i)
{
	unsigned char j;
	while(i--)
	{	
		for(j=0;j<255;j++)
		{;}
	}
}

void delay500us()
{
uchar j;

for(j=0;j<57;j++)
{;}
}
 delay_ms(int n)	//1000���һ��
		   {  int i ,j;
		   for(;i<n;i++)
		   {
		   for(j=0;j<255;j++);
		   }
		   }


		   void delay128(int ms)                //延时ms
{
        while(ms--)
        {
                int i;
                for(i=25;i>0;i-- ); 
        }
}
 void delay5(uint n)
		 {
		 	do
			{
				_nop_();
				_nop_();
				_nop_();
				n--;
			}while(n);
		 }