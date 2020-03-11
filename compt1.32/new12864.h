
uchar number[]={'0','1','2','3','4','5','6','7','8','9',}	   ;
 
#define DATA_PORT P2
sbit LCD12864_EN   = P0^5;
sbit LCD12864_RSET = P0^3;
sbit LCD12864_RS   = P0^7;
sbit LCD12864_RW   = P0^6;
sbit LCD12864_PSB  = P0^4;

bit LcdBusyCheck(){
          bit result;
          LCD12864_RS = 0;
          LCD12864_RW = 1;
          LCD12864_EN = 1;
          result = (bit)(DATA_PORT&0x80);
          LCD12864_EN = 0;
          return result;
}

void WriteCmdToLCD(unsigned char cmd)
{
                //        while(LcdBusyCheck());
        	delay128(10);
          LCD12864_RS = 0;
          LCD12864_RW = 0;
          LCD12864_EN = 1;
          DATA_PORT = cmd;
          delay128(5);
        LCD12864_EN = 0;
        delay128(5);
        LCD12864_EN = 1;

}

	  busy()
	  {
	  bit is;
	  while(1)
	  {
	  is=LcdBusyCheck();
	   if(is==0)break;
	   }
	  }


void WriteDatToLcd(unsigned char dat)
{
                //while(LcdBusyCheck());
                delay128(10);
                LCD12864_RS = 1;
          LCD12864_RW = 0;
          LCD12864_EN = 1;
          DATA_PORT = dat;
          delay128(5);
        LCD12864_EN = 0;
        delay128(5);
        LCD12864_EN = 1;

}


void WriteStrToLcd(unsigned char *str)
{
        while(*str != '\0')
        {
                WriteDatToLcd(*str++);
                delay128(5);
        }
}





void LcdPos(unsigned char x,unsigned char y)
{
        unsigned char pos;
        if(x == 0)//��һ��
        {
                x = 0x80;
        }else if(x == 1) //�ڶ���
        {
                x = 0x90;
        }else if(x == 2)  //������
        {
                x = 0x88;
        }else if(x == 3) //������
        {
                x = 0x98;
        }
        pos = x + y;
        WriteCmdToLCD(pos);
}


void LcdInit()
{
        LCD12864_PSB = 1;
         LCD12864_RSET = 0;
         delay128(10);
        LCD12864_RSET = 1;

        WriteCmdToLCD(0x30);	  //����չָ��
        delay128(5);
        WriteCmdToLCD(0x30);	  //����չָ��
        delay128(5);
        WriteCmdToLCD(0x18);	  //��ʾ����,�α����1��
        delay128(5);
        WriteCmdToLCD(0x10);//�α������ƶ�
        delay128(5);
        WriteCmdToLCD(0x01);  //����

        delay128(5);
        WriteCmdToLCD(0x06);//�α�ÿд��һ����������
        delay128(5);
         WriteCmdToLCD(0x0c);//����ʾ,����ʾ�α�
        delay128(5);


}
void Clr()
{                                
                        
                                P0 = 0xff;
                                LcdInit();
}


void show(uchar x,uchar y,char *str)	//str�ܳ���16��uchar
{
	LcdPos(x,y);
	WriteStrToLcd(str);
	delay128(5);

}
void gundong()
{

uchar i=0;
for(i=0;i<5;i++)
{
   	show(i%4,0,		"���ܰ�ȫ����ϵͳ");
	show((i+1)%4,0,	"�Ŷ�: ����kui   ");
	show((i+2)%4,0,	"      ����      ");
	show((i+3)%4,0,	"      Ǯ��      ");
		delay1ms(200);	
}

}
void screen0()
{
	show(0,1,"���ܰ�ȫ����  ");
	show(1,0,"      ϵͳ      ");
	show(2,0,"�Ŷ�: ����");
	show(3,0,"����  Ǯ��");

}
void screen1()
{
					
uchar temp[2];


  
 if(isArriving[0]==1)
	{
		show(0,0,"1");	
	}
		else
	{	
		show(0,0,"  ");
	}
		
	if(isArriving[1]==1)
	{
	show(0,1,"2");	
	}
		else
	{	
		show(0,1,"  ") ;
	}
		
	if(isArriving[2]==1)
	{
	show(0,2,"3");	
	}
		else
	{	
		show(0,2,"  ")	;
	}
		
	if(isArriving[3]==1)
	{
	show(0,3,"4");
		
	}
		else
	{	
		show(0,3,"  ")	 ;
	}
		
	if(isArriving[4]==1)
	{
		show(0,4,"5");
	}
		else
	{	
		show(0,4,"  ")	  ;
	}
		
	if(isArriving[5]==1)
	{
			show(0,5,"6");
	}
		else
	{	
		show(0,5,"  ")	   ;
	}
		
	if(isArriving[6]==1)
	{
			 show(0,6,"7");
	}
		else
	{	
		show(0,6,"  ")		;
	}
		
	if(isArriving[7]==1)
	{
	show(0,7,"8");
		
	}
		else
	{	
		show(0,7,"  ")		 ;
	}
		
	if(isArriving[8]==1)
	{
			show(1,0,"9");
	}
		else
	{	
		show(1,0,"  ")		  ;
	}
		
	if(isArriving[9]==1)
	{
					show(1,1,"10");
	}
		else
	{	
		show(1,1,"  ")		   ;
	}
		
	if(isArriving[10]==1)
	{
					   show(1,3,"11");
	}
		else
	{	
		show(1,3,"  ")			;
	}
		
	if(isArriving[11]==1)
	{
					show(1,5,"12");
	}	
	else
	{	
		show(1,5,"  ")			 ;
	}
	
		if(isArriving[12]==0)
	{
	show(2,0,"�ѵ���!!!!");
	temp[0]=number[CurrentFloor/10];
	temp[1]=number[CurrentFloor%10];
		show(2,5,temp);
		
	}
	else
	{																	   
		show(2,0,"������  ǰ��");
		temp[0]=number[floor/10];
		temp[1]=number[floor%10];
		show(2,6,temp);
	}




show(3,1,"����: ");
temp[0]=number[tem/10];
temp[1]=number[tem%10];
show(3,3,temp);
		
}
void screen2()
{
	show(0,0,"���ֿ���!");
	show(1,0,"�������ѿ�");	
}
void screen3()
{
	uchar nian[4];
	uchar jie[2];
	nian[0]=number[readtime[0]];
	nian[1]=number[readtime[1]];
	nian[2]=number[readtime[2]];
	nian[3]=number[readtime[3]];
	show(0,0,nian);
	show(0,2,"��");
	jie[0]=number[readtime[4]];
	jie[1]=number[readtime[5]];
	show(0,3,jie);
	show(0,4,"��");
	jie[0]=number[readtime[6]];
	jie[1]=number[readtime[7]];
	show(0,5,jie);
	show(0,6,"��");
	jie[0]=number[readtime[8]];
	jie[1]=number[readtime[9]];
	show(1,0,jie);
	show(1,1,"ʱ");
	jie[0]=number[readtime[10]];
	jie[1]=number[readtime[11]];
	show(1,2,jie);
	show(1,3,"��");
	jie[0]=number[readtime[12]];
	jie[1]=number[readtime[13]];
	show(1,4,jie);
	show(1,5,"��");
	jie[0]=number[readtime[14]];
	jie[1]=' ';
	show(2,0,"����");
	show(2,2,jie);
	

	
}

void showTime()
{
int i=0;
ds1302_read_time();  //��ȡʱ�� 

  readtime[0]=(time_buf[0]>>4);   //�������ǧλ
  readtime[1]=(time_buf[0]&0x0F); //��������λ 
  readtime[2]=(time_buf[1]>>4);   //�������ʮλ
  readtime[3]=(time_buf[1]&0x0F); //��������λ 

  readtime[4]=(time_buf[2]>>4);   //�������ʮλ
  readtime[5]=(time_buf[2]&0x0F); //������¸�λ 

  readtime[6]=(time_buf[3]>>4);   //�������ʮλ
  readtime[7]=(time_buf[3]&0x0F); //������ո�λ 

  readtime[8]=(time_buf[4]>>4);   //�����Сʱʮλ
  readtime[9]=(time_buf[4]&0x0F); //�����Сʱ��λ 
  readtime[10]=(time_buf[5]>>4);   //���������ʮλ
  readtime[11]=(time_buf[5]&0x0F); //��������Ӹ�λ
  readtime[12]=(time_buf[6]>>4);   //���������ʮλ
  readtime[13]=(time_buf[6]&0x0F); //��������Ӹ�λ   
  readtime[14]=(time_buf[7]);
  Delay_xms(50);
  screen3();
  
}
