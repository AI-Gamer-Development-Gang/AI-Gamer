import numpy as np
import cv2
from matplotlib import pyplot as plt
###########################################################################
# loading, cutting interesting for us part and resizing
img = cv2.imread('E:\\Scrinysmieci2.0\\doodle2.jpg') #normally there will be a screen straight from doodle game
                                                        
img = img[75:110, 5:100]                                 

scale_percent = 220 # percent of original size         
width = int(img.shape[1] * scale_percent / 100)
height = int(img.shape[0] * scale_percent / 100)
dim = (width, height)
img = cv2.resize(img, dim,interpolation = cv2.INTER_AREA)

############################################################################
# *magic*, preprocessing image to find only digit in white and background in black:
# (probably can be done easier)
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
ret, thresh = cv2.threshold(gray,0,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)

kernel = np.ones((2,2),np.uint8)
opening = cv2.morphologyEx(thresh,cv2.MORPH_OPEN,kernel, iterations = 2)

dist_transform = cv2.distanceTransform(opening,cv2.DIST_L2,5)
ret, sure_fg = cv2.threshold(dist_transform,0.4*dist_transform.max(),255,0)

sure_fg = np.uint8(sure_fg)
# sure_fg is ready to find contours

############################################################################
# finding contours and creating rectangle around digit:
contours, hierarchy = cv2.findContours(sure_fg, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

for cnt in reversed(contours):  # iterating through every digit
    x,y,w,h = cv2.boundingRect(cnt) 
    print(x,y,w,h)
    #TO DO:
    # cutting this part of image and throwing it into cnn >>> recognizing which digit is that

# debbuging purposes:
rect = cv2.rectangle(sure_fg,(x,y),(x+w,y+h),(100,100,100),2)

cv2.imshow("cropped2", rect) 

