
#define uchar unsigned char
#define uint  unsigned int
//DS1302���Ŷ���,�ɸ���ʵ����������޸Ķ˿ڶ���
sbit RST=P0^1;
sbit IO=P3^5;
sbit SCK=P3^4;
//DS1302��ַ����
#define ds1302_sec_add			0x80		//�����ݵ�ַ
#define ds1302_min_add			0x82		//�����ݵ�ַ
#define ds1302_hr_add			0x84		//ʱ���ݵ�ַ
#define ds1302_date_add			0x86		//�����ݵ�ַ
#define ds1302_month_add		0x88		//�����ݵ�ַ
#define ds1302_day_add			0x8a		//�������ݵ�ַ
#define ds1302_year_add			0x8c		//�����ݵ�ַ
#define ds1302_control_add		0x8e		//�������ݵ�ַ
#define ds1302_charger_add		0x90 					 
#define ds1302_clkburst_add		0xbe
//��ʼʱ�䶨��
uchar time_buf[8] = {0x20,0x19,0x12,0x25,0x18,0x00,0x00,0x03};//��ʼʱ��
uchar readtime[15];//��ǰʱ��
uchar sec_buf=0;  //�뻺��
uchar sec_flag=0; //���־λ
//����:��ʱ1����
//��ڲ���:x
//���ڲ���:��
//˵��:����Ϊ12M
void Delay_xms(uint x)
{
  uint i,j;
  for(i=0;i<x;i++)
    for(j=0;j<112;j++);
}
//DS1302��ʼ������
void ds1302_init(void) 
{
	RST=0;			//RST���õ�
	SCK=0;			//SCK���õ�
}
//��DS1302д��һ�ֽ�����
void ds1302_write_byte(uchar addr, uchar d) 
{
	uchar i;
	RST=1;					//����DS1302����	
	//д��Ŀ���ַ��addr
	addr = addr & 0xFE;   //���λ���㣬�Ĵ���0λΪ0ʱд��Ϊ1ʱ��
	for (i = 0; i < 8; i ++) {
		if (addr & 0x01) {
			IO=1;
			}
		else {
			IO=0;
			}
		SCK=1;      //����ʱ��
		SCK=0;
		addr = addr >> 1;
		}	
	//д�����ݣ�d
	for (i = 0; i < 8; i ++) {
		if (d & 0x01) {
			IO=1;
			}
		else {
			IO=0;
			}
		SCK=1;    //����ʱ��
		SCK=0;
		d = d >> 1;
		}
	RST=0;		//ֹͣDS1302����
}

//��DS1302����һ�ֽ�����
uchar ds1302_read_byte(uchar addr) {

	uchar i,temp;	
	RST=1;					//����DS1302����
	//д��Ŀ���ַ��addr
	addr = addr | 0x01;    //���λ�øߣ��Ĵ���0λΪ0ʱд��Ϊ1ʱ��
	for (i = 0; i < 8; i ++) {
		if (addr & 0x01) {
			IO=1;
			}
		else {
			IO=0;
			}
		SCK=1;
		SCK=0;
		addr = addr >> 1;
		}	
	//������ݣ�temp
	for (i = 0; i < 8; i ++) {
		temp = temp >> 1;
		if (IO) {
			temp |= 0x80;
			}
		else {
			temp &= 0x7F;
			}
		SCK=1;
		SCK=0;
		}	
	RST=0;					//ֹͣDS1302����
	return temp;
}
//��DS302д��ʱ������
void ds1302_write_time(void) 
{
	ds1302_write_byte(ds1302_control_add,0x00);			//�ر�д���� 
	ds1302_write_byte(ds1302_sec_add,0x80);				//��ͣʱ�� 
	//ds1302_write_byte(ds1302_charger_add,0xa9);	    //������ 
	ds1302_write_byte(ds1302_year_add,time_buf[1]);		//�� 
	ds1302_write_byte(ds1302_month_add,time_buf[2]);	//�� 
	ds1302_write_byte(ds1302_date_add,time_buf[3]);		//�� 
	ds1302_write_byte(ds1302_hr_add,time_buf[4]);		//ʱ 
	ds1302_write_byte(ds1302_min_add,time_buf[5]);		//��
	ds1302_write_byte(ds1302_sec_add,time_buf[6]);		//��
	ds1302_write_byte(ds1302_day_add,time_buf[7]);		//�� 
	ds1302_write_byte(ds1302_control_add,0x80);			//��д����     
}
//��DS302����ʱ������
void ds1302_read_time(void)  
{
	time_buf[1]=ds1302_read_byte(ds1302_year_add);		//�� 
	time_buf[2]=ds1302_read_byte(ds1302_month_add);		//�� 
	time_buf[3]=ds1302_read_byte(ds1302_date_add);		//�� 
	time_buf[4]=ds1302_read_byte(ds1302_hr_add);		//ʱ 
	time_buf[5]=ds1302_read_byte(ds1302_min_add);		//�� 
	time_buf[6]=(ds1302_read_byte(ds1302_sec_add));//�룬������ĵ�7λ�����ⳬ��59
	time_buf[7]=ds1302_read_byte(ds1302_day_add);		//�� 	
}


//������
/*

void doing(void)
{ 
 Delay_xms(50);//�ȴ�ϵͳ�ȶ�
 ds1302_init(); //DS1302��ʼ��
 Delay_xms(10);
 ds1302_write_time(); //д���ʼֵ
 while(1)
  { 
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

   Delay_xms(1000);
 
  }
}	
*/	
