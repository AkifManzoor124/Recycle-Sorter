import urllib
import urllib2
import cv2
import numpy as np
import os

def store_raw_images():
    neg_images_link = 'http://image-net.org/api/text/imagenet.synset.geturls?wnid=n04255586'
    neg_image_urls = urllib2.urlopen(neg_images_link).read().decode()
    pic_num = 1
    
    if not os.path.exists('pos'):
        os.makedirs('pos')
        
    for i in neg_image_urls.split('\n'):
        try:
            print(i)
            urllib.urlretrieve(i, "pos/"+str(pic_num)+".bmp")
            img = cv2.imread("pos/"+str(pic_num)+".bmp")
            # should be larger than samples / pos pic (so we can place our image on it)
            resized_image = cv2.resize(img, (400, 400))
            cv2.imwrite("pos/"+str(pic_num)+".bmp",resized_image)
            pic_num += 1

        except Exception as e:
            print(str(e))          

store_raw_images()
