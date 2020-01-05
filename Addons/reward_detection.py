import numpy as np
import cv2
from matplotlib import pyplot as plt

img = cv2.imread('E:\\Scrinysmieci2.0\\doodle2.jpg') #normally there will be a screen straight from doodle game
img = img[75:110, 5:100]

scale_percent = 220 # percent of original size
width = int(img.shape[1] * scale_percent / 100)
height = int(img.shape[0] * scale_percent / 100)
dim = (width, height)
img = cv2.resize(img, dim,interpolation = cv2.INTER_AREA)
                 
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
ret, thresh = cv2.threshold(gray,0,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)

kernel = np.ones((2,2),np.uint8)
opening = cv2.morphologyEx(thresh,cv2.MORPH_OPEN,kernel, iterations = 2)
#sure_bg = cv2.dilate(opening,kernel,iterations=3)
#ENOUGH ^^^
dist_transform = cv2.distanceTransform(opening,cv2.DIST_L2,5)
ret, sure_fg = cv2.threshold(dist_transform,0.4*dist_transform.max(),255,0)

sure_fg = np.uint8(sure_fg)
#unknown = cv2.subtract(sure_bg,sure_fg)

cv2.imshow("cropped2", sure_fg) #   <<< sure_fg ready to split and then to recognize image
print('???')
