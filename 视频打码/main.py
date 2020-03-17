import cv2 as cv
import configparser
import os
import sys

def trainfor_video(filepath,param):
    if os.path.exists(filepath)==False:
        print("文件不存在")
        exit()
    print("开始检测人脸,请等待...")
    videocapture=cv.VideoCapture(filepath)
    h = videocapture.get(cv.CAP_PROP_FRAME_HEIGHT)
    w = videocapture.get(cv.CAP_PROP_FRAME_WIDTH)
    fps = videocapture.get(cv.CAP_PROP_FPS)
    total = videocapture.get(cv.CAP_PROP_FRAME_COUNT)
    videowriter=cv.VideoWriter( 'temp.mp4',
                                cv.VideoWriter_fourcc('m', 'p', '4', 'v'),
                                fps,
                                (int(w),int(h))
                                )
    i=0;
    while True:
        ret,frame=videocapture.read()
        if ret==False:
            break;
        gray=cv.cvtColor(frame,cv.COLOR_BGR2GRAY)
        face_cascade=cv.CascadeClassifier('haarcascade_frontalface_default.xml');
        faces=face_cascade.detectMultiScale(gray,1.1,int(param))
        for x,y,w,h in faces:
            image = frame[y:y + h, x:x + w]
            image = cv.GaussianBlur(image, (0, 0), 15)
            frame[y:y + h, x:x + w] = image
        videowriter.write(frame)
        i=i+1;
        str='\r'+'process:'+format(i*100//total)+'%'
        sys.stdout.write(str)

    videowriter.release()
    videocapture.release()
    print('检测成功')

def get_ini():
       parser= configparser.ConfigParser();
       parser.read('config.ini')
       filepath=parser.get('video','filepath')
       savepath=parser.get('video','savepath')
       param = parser.get('video', 'param')
       return filepath,savepath,param
def combine(filepath,savepath):
    f1=os.popen('ffmpeg -i '+filepath+' -vcodec copy -vn output.mp3')
    print(f1.read())
    f2=os.popen('ffmpeg -i temp.mp4 -acodec copy -an output.mp4')
    print(f2.read())
    f3=os.popen('ffmpeg -i output.mp4 -i output.mp3 '+savepath)
    print(f3.read())

def deal_end():
    if os.path.exists("output.mp3"):
        os.remove('output.mp3')
    if os.path.exists('output.mp4'):
        os.remove('output.mp4')
    if os.path.exists('temp.mp4'):
        os.remove('temp.mp4');

filepath,savepath,param=get_ini()
#print(int(param))
print(filepath,savepath)
trainfor_video(filepath,param)
combine(filepath,savepath)
deal_end()




