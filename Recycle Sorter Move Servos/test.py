import numpy as np
import cv2

# multiple cascades: https://github.com/Itseez/opencv/tree/master/data/haarcascades

#https://github.com/Itseez/opencv/blob/master/data/haarcascades/haarcascade_frontalface_default.xml
tims_cup_cascade = cv2.CascadeClassifier('C:\\Users\\Akif Manzoor\\Desktop\\Recycle Sorter Move Servos\\cascade.xml')
large_box_cascade = cv2.CascadeClassifier('C:\\Users\\Akif Manzoor\Desktop\\Recycle Sorter Move Servos\\LargeBox.xml')

cap = cv2.VideoCapture(0)

while 1:
    ret, img = cap.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    tims_cup = tims_cup_cascade.detectMultiScale(gray, 1.3, 5)
    large_box = large_box_cascade.detectMultiScale(gray, 1.3, 5)

    for (x,y,w,h) in tims_cup:
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = img[y:y+h, x:x+w]

    for (x,y,w,h) in large_box:
        cv2.rectangle(img,(x,y),(x+w,y+h),(0,0,255),2)
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = img[y:y+h, x:x+w]
    

    cv2.imshow('img',img)
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break

cap.release()
cv2.destroyAllWindows()
