			 unsigned char code F_Rotation[4]={0x01,0x02,0x04,0x08};//��ת���
			unsigned char code B_Rotation[4]={0x08,0x04,0x02,0x01};//��ת���
		  #define dj P3
		  uint ce;
		   
void Delay(unsigned int i)//��ʱ
{
 while(--i);              
}

  	turnN()
  	{
	
	uchar i=0;
	for(ce=0;ce<500;ce++)
	{
 	 for(i=0;i<4;i++)      //4��
     {
	     dj=F_Rotation[i];  //�����Ӧ���� �������л��ɷ�ת���
	     Delay(500);        //�ı�����������Ե������ת��
	 }

	 }
   }
   turnS()
   {
   uchar i=0;
   	for(ce=0;ce<500;ce++)
	{
    for(i=0;i<4;i++)      //4��
     {
	     dj=B_Rotation[i];  //�����Ӧ���� �������л��ɷ�ת���
	      Delay(500);        //�ı�����������Ե������ת��
	 }
	 }
	 
   }
   void execute()
   { 
   
   	 int temp,time,i;
	
	 temp=(int)floor;
	 time=floor-CurrentFloor;
	 notify();
	 if(time<0)
	 {
	 	
		for(i=0;i<-time;i++)
		{
			turnN();  	TR1=0;
			screen1();	TR1=1;
			
		}
		isArriving[floor-1]=0;
	 }
	 if(time>0)
	 {
	 	for(i=0;i<time;i++)
		{
			turnS();
			TR1=0;
				screen1();
			
					TR1=1;
		}
		isArriving[floor-1]=0;	
	 }
	 if(time==0)
	 {
	 	 isArriving[floor-1]=0;
		 TR1=0;
		 screen1();
	
		 TR1=1;	
	 }
	 
	 notify();
	 isArriving[12]=0; 

	 CurrentFloor=floor;
	
   }
  