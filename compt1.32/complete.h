
			#define uchar unsigned char
			#define uint unsigned int
			#define false 0
			#define true 1

		
		
	
			sbit bee =P3^6;	//������
			sbit door=P0^0;
			sbit led=P0^2;	//��������
	  	    uchar floor=0;	 //ǰ��¥��
			uchar CurrentFloor=5; //��ǰ¥��
	  		uchar isArriving[16]={0};//1��ʾ���˰��£�2��ʾ������Ӧ¥��			 //isArriving[12]Ϊ�ſ�λ 0��1��
 			uint tem=0;			//��ǰ�¶�
	  /*
	  ������������ʾ����ʾ���ֹ���5s��¥����ʾһ�㣬��wck�ж��������㣬qy����һ��¥������
	  �����ɹ���isArriving=true ���ݸ�qy ����ʾ����ʾ���Ｘ�㣬isArriving=false�� wck�����¶ȸ�qy������¶ȳ���35���϶�
	  ���ֱ�����������һֱ�죬�ƻ�һֱ�����̵���ǿ�д򿪡���Ļ��ʾ���������ˣ���ҿ��ܡ�
	  */
	  /*
	  �ſ��ţ��ж��˰��°���������173����Ӧ�������true��һ��ʼ��5¥�����¹رյ����ţ�excute��ִ����ȥ����ģ��Ŵ򿪣�
	  */



	  
