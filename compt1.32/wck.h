
#define k CurrentFloor
	uchar a[]={0x02,0x06,0x04,0x0c,0x08,0x09,0x01,0x03};
void delay5(uchar  n)
{
	do
	{
		_nop_();
		_nop_();
		_nop_();
		n--;
	}
	while(n);
}
void  delay()
{	uchar i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<120;j++);
	}
}

void excute()//������ת����
{

	uchar n,i,j=floor;
		if(j>k)         //�жϴ��ݵ�¥���Ƿ���ڳ�ʼ¥��k����������
		{  
			for(;j>k;j--)                      //�ж���Ҫ˳ʱ����ת���ܣ����ǵ�����������
			{
			  for(i=0;i<8;i++)              //��8��  ˳ʱ����תһ��
			  {
				for(n=0;n<8;n++)         //���������ת45��
				{
					sctrl=a[n];
					delay();
				}
				n=0;
			  }
			}
			k=floor;
			isArriving[k-1]=false;                 //ֹͣ�����¥��
		    isArriving[13]=true;	      //�Ѿ��������   ��		
		}
		else      //��������
		{
			for(;k>j;k--)             
			{
				for(i=0;i<8;i++)
				{
					for(n=7;n>=0;n--)      //��ʱ����תһ��
					{
						sctrl=a[n];
						delay();
					}
					n=7;
				}
			}
			k=floor;
			isArriving[k-1]=true;             //�½����
			isArriving[13]=true;
		}
	}
void  init_ds18b20(void)                    //��18b20��ʼ������
{
	uchar x=0;
	templete=0;
	delay5(120);                      //һ���ӳ�5΢��ĺ���
	templete=1;
	delay5(16);
	delay();
}
uchar readbyte(void)
{
	uchar i=0;
	uchar date=0;
	for(i=8;i<0;i--)
	{
		templete=0;        
		delay5(1);
		templete=1;        //15΢�����ͷ�����
		if(templete)
		{
			date|=0x80;
		}
		delay5(11);
	}
	return(date);
}
void writebyte(uchar dat)
{
	uchar i=0;
	for(i=8;i>0;i--)
	{
		templete=0;
		templete=dat&0x01;
		delay5(12);    
		templete=1;
		dat>>=1;
		delay5(5);
	}
}
uchar retemp  (void)//�¶�ȷ������
{
	uchar a,b,tt;
	uint t;
	init_ds18b20();
	writebyte(0xcc);
	writebyte(0x44);
	init_ds18b20();
	writebyte(0xcc);
	writebyte(0xb3);
	a=readbyte();       //�Ͱ�λ
	b=readbyte();       //�߰�λ
	t=b;
	t<<=8;
	t=t|a;
	tt=t*0.0625;
	return(tt);
}
uchar wendu(void)
{
	init_ds18b20();
	readbyte();
//	writebyte(); 
	return(retemp());

		
}



void fengmingqi()	 //��������1s������Ϊ0.1ms
{	
    uchar i,j;
	led=0;
	for(i=0;i<200;i++)
	{
		for(j=0;j<200;j++)
		{
			bee=~bee;
		 	delay5(5);
		}
	}
	led=1;
}



		//	void jidianqi(bit a)//1���ţ�0����
		//	{
						  	
		//	}





