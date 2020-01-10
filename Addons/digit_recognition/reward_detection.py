import numpy as np
import cv2
from matplotlib import pyplot as plt
# http://ufldl.stanford.edu/housenumbers/
#   img = cv2.imread('E:\\Scrinysmieci2.0\\doodle2.jpg') #normally there will be a screen straight from doodle game
#   img = img[75:110, 5:100]
'''
def preprocess(img, scale_percent = 220):

    width = int(img.shape[1] * scale_percent / 100)
    height = int(img.shape[0] * scale_percent / 100)
    dim = (width, height)
    img = cv2.resize(img, dim, interpolation=cv2.INTER_AREA)

    hsv_img = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    lightgreen = np.uint8([[[156, 227, 199]]])
    darkgreen = np.uint8([[[26,84,55 ]]])
    #bgr_black = np.uint8([[[0, 0, 0]]])
    
    hsv_lightgreen = cv2.cvtColor(lightgreen,cv2.COLOR_BGR2HSV)
    hsv_darkgreen = cv2.cvtColor(darkgreen,cv2.COLOR_BGR2HSV)
    
    mask = cv2.inRange(hsv_img, hsv_lightgreen, hsv_darkgreen)
    #mask = cv2.bitwise_not(mask, mask)
    res = cv2.bitwise_and(img, img, mask=mask)
    #hsv = cv2.cvtColor(res, cv2.COLOR_HSV2BGR)
    return res
    
    gray = cv2.cvtColor(res, cv2.COLOR_BGR2GRAY)
    ret, thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)

    kernel = np.ones((2, 2), np.uint8)
    opening = cv2.morphologyEx(thresh, cv2.MORPH_OPEN, kernel, iterations=2)
    
    
    return opening
    

def extract_digits(img):
    # finding contours and creating rectangle around digit:
    arr = []
    contours, hierarchy = cv2.findContours(img, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    for cnt in reversed(contours):  # iterating through every digit
        x, y, w, h = cv2.boundingRect(cnt)
        tmp = img[y:y+h, x:x+w].copy()        # tmp = img[y:y+h+5, x:x+w].copy()
        done = cv2.resize(tmp, (32, 32), interpolation=cv2.INTER_AREA)
        arr.append(done)

    return arr
    
# debbuging purposes:
#rect = cv2.rectangle(sure_fg,(x,y),(x+w,y+h),(100,100,100),2)

#cv2.imshow("cropped2", done)
'''

