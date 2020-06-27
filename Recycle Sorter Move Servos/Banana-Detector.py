import numpy as np
import cv2
import serial

# multiple cascades: https://github.com/Itseez/opencv/tree/master/data/haarcascades
#https://github.com/Itseez/opencv/blob/master/data/haarcascades/haarcascade_frontalface_default.xml

tims_cup_cascade = cv2.CascadeClassifier('C:\\Users\\Akif Manzoor\Desktop\\Recycle Sorter Move Servos\\cascade.xml')
large_box_cascade = cv2.CascadeClassifier('C:\\Users\\Akif Manzoor\\Desktop\\Recycle Sorter Move Servos\\LargeBox.xml')

cap = cv2.VideoCapture(1)

usbport = 'com3'
ser = serial.Serial(usbport, 9600, timeout=1)
flag = True

def move(servo):
    ser.write(chr(255))
    ser.write(chr(servo))

def reset():
    global flag
    flag = True;
    start()


def start():
    global flag
    
    while 1:
        ret, img = cap.read()
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        tims_cup = tims_cup_cascade.detectMultiScale(gray, 1.3, 5)
        large_box = large_box_cascade.detectMultiScale(gray, 1.3, 5)

        print('Detecting')
        
        for (x,y,w,h) in large_box:
            cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
            roi_gray = gray[y:y+h, x:x+w]
            roi_color = img[y:y+h, x:x+w]
            if flag == True:
                move(1)
                flag = False
                
        for (x,y,w,h) in tims_cup:
            cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
            roi_gray = gray[y:y+h, x:x+w]
            roi_color = img[y:y+h, x:x+w]
            if flag == True:
                move(0)
                flag = False
    
        #cv2.imshow('img',img)

        if flag == False:
            break

##cv2.waitKey(0)
##cap.release()
##cv2.destroyAllWindows()
