��Һ�,����Ray,�������Ҵ���һ��ʹ��
	adb���ж԰�׿��ģ����,����������
	opencv���з���ͼƬ�Ƿ�ƥ���Լ�ƥ��λ��,ƥ�����ƶ�,��ͼ�Ȳ���
	jni������ϵC++д��opencv�Ĳ���

����,��Ҫʹ��adb,��Ҫ������ļ������ļ��е�adb�ļ�����ϵͳ��������path,
��������ҾͲ�������,������jdk��������һ��,֮����cmd����adb�������Ϣ��
���ʹ������óɹ�.

һ����˵�ⲽ��������Ҫ,���������ʱ���ǳ��쳣���߱�ȱ��dll,���
opencv_world347.dll����һ���ļ�����:
C:\Windows\System32
C:\Windows\SysWOW64

֮��Ϳ���ʹ����jar����,�Ұ����еĿ�ܶ�����adb_jni_opencv_auto.jar��
���ʹ��ʱ����Ҫ�������jar������
======================================
adb_jni_opencv_auto.jar��������Ҫ����,�ֱ���
ADB_Model, Dection, FeatureDection
�������඼����cn.createqy.autoScripts���package��
������adb_jni_opencv_auto.jar�İ����ĵ�
==================================
ADB_Model��ĸ���point��//����ֻΪ�˷������,��ʹ�ô���ADB_Model�ڵķ���Ҳ��ʵ��
	class point
	{
    	int x=-1;
    	int y=-1;
    	public point(int x,int y)
    	{
      		  this.x=x;
        		this.y=y;
    	}
	}
===========================	
ADB_Model��:	//�������Ҫ�����android����ģ�����
���⹫������:
	public String connect_WIFI_ROOT(String ipPAth);
		/*adb���������ӷ�ʽ,һ����ͨ��usbֱ������,
		 *���ӵ�ͬʱ��Ҫ��usb����,��������ļ�,ps:����ֻҪ��ĵ����ܹ����ʵ��ֻ��ļ�������
		 *�������ͨ��wifi����,��ô����Ҫ�ȵ����������,���������Ҫ�ֻ�root
		 *����ipPath�����ֻ���ip��ַ,����ֵ��cmd���ص���Ϣ,�������null��˵��ʧ��*/

	public String touch(point p) ;
		//ģ�ⰴ���ֻ���λ��p�ĵ�
		
	 public String touch(int x,int y);
		//ģ�ⰴ���ֻ���λ��(x,y)����ĵ�

	public String input_string(String s);
		//ģ�����ֻ��Ľ��㴦�����ַ���s

	public String   swipe(point a,point b,int time_m);
		//ģ����ʱ��m�ڴ��ֻ���a�㻬��b��,mΪ����
		//���a��b�൱,�Ϳ��԰�סĳһ��m����

	 public String   swipe(int x1,int y1,int x2,int y2,int time_m) ;
		//ģ����ʱ��m�ڴ�(x1,y1)���껬����(x2,y2)����
		//���(x1,y1)��(x2,y2)
		
	 public String home() ;
		//ģ�ⷵ����ҳ��,�൱���ֻ���home��
	
	public String back();
		//ģ�ⷵ��,�൱���ֻ���back��
	
	 public String turnLeft();
		//ģ�����󻬶���Ļ#��̫����,��ʱ��ʧ��,������swipe����
	
	public String turnRight()
		//ģ�����һ�����Ļ#��̫����,��ʱ��ʧ��,������swipe����

	public String Screen_Shot(String path) 
		//���ֻ����н���,����ͼƬ����path·�����ļ���
===========================================================
Dection��:
/*����һ������talk.dll��ԭʼ��װ��,���ûѧ��jni����û����Դ��,��ô���Ƽ�����ʹ�������,������Ϊ���
 *������������
 *jni��һЩ�㿴�������쳣,����ʹ�������Ҳ�Ǻ��кô���,�������������ķ�װ��FeatureDection��˵,
 *����Ч�ʱ�FeatureDection�ߺö౶*/

//����಻����ʹ��new������,��ֻ����ʹ�����ľ�̬����getInstance�����������Ψһ�����

	 public static void set_TALK_DLL_PATH(String path);
		/*ʹ����������һ��Ҫ�ȵ��������̬����,path��talk.dll(����ļ��ѷ��ڵ�ǰ�ļ�����)
		*������·��,·������
		*Ҫд����,��Ȼ����쳣,��������src/..����,�������ֻ�����һ�μ���
		*/

	 public static Detection getInstance() ;
		/*
		*��������ǻ��DectionΨһ�����ķ���,ʹ��֮ǰһ��Ҫvoid set_TALK_DLL_PATH
		��ΪDection��ֻ����ӵ��һ�������,������ӵ����������
		*/

	public native void input_Image(String primary_image_path,String match_image_path) ;
		/*��������ͼƬ,����primary_image_path��ҪԭʼͼƬ·��,
		*match_image_path��Ҫƥ���ͼƬ·��,���ͼƬ������ԭʼͼƬ��һС����
		*���൱���Ƕ�talk.dll�ĳ�ʼ��
		*��Ҫ����ͼƬҲֻ��ı���������Ĳ�����·������,��Ҫע�����,�ı��Ҳ���
		*���µ�get_x,get_y,get_sample��������ˢ��
		*/
	public native float get_sample();
		/*
			������input_image������,�ٵ�������������������ͼƬ�����ƶ�,һ����Ϊ���ص�ֵ����0.93��Ϊ����
		*/
		
    	public native int    get_x();
		/*
			
			������input_image������,�ٵ�������������ƥ��ͼƬ��ԭʼͼƬ�������Ƶ�x�����λ��

		*/
    	public native int    get_y();
		/*
			
			������input_image������,�ٵ�������������ƥ��ͼƬ��ԭʼͼƬ�������Ƶ�y�����λ��

		*/
   	public native void debug_show_Image();
		/*
			������input_image������,��������Ὣƥ��ͼ���÷�����ԭʼͼ���غ�,��������Ļ����ʾ�Ҷ�ͼ��

		*/
    
    public native void Image_Cap(int x, int y, int width, int height, String read_path, String save_path) ;
		/*
			���������������input_image����,����Ϊ��ʵ��ͼ��Ĳü�
			xΪ�ü�λ�õ�x����
			yΪ�ü�λ�õ�y����
			widthΪ�ü�ͼƬ�Ŀ��
			heightΪ�ü�ͼƬ�ĸ߶�
			read_pathΪ��ȡҪ���ü���ͼƬ��·��
			save_pathΪ�ü���Ҫ�����·��
		*/

//����������е�С����,������ʾ�����뽫����example�ļ���
=============================================
FeatureDection��ΪDection�ķ�װ��,������new����,����Ҳ�򵥵Ķ�
���췽��:
	FeatureDection(String full_path,String primary_image_path,String match_image_path);
		//��һ������Ϊtalk.dll������·��,�ڶ�������ΪԭʼͼƬ,����������ΪҪƥ���ͼƬ
�����
	x:ƥ�����λ�õ�x����
	y:ƥ�����λ�õ�y����
	sample:ƥ�����ƶ�
���ⷽ��
	void showImage()
		//��ʾƥ����ͼƬ,��debug_show_Image()����
	public  void Image_Cap(int x, int y, int width, int height, String read_path, String save_path)
		//��ͼ.��Image_Cap����