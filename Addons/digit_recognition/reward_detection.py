import numpy as np
import cv2
from matplotlib import pyplot as plt
# http://ufldl.stanford.edu/housenumbers/
#   img = cv2.imread('E:\\Scrinysmieci2.0\\doodle2.jpg') #normally there will be a screen straight from doodle game
#   img = img[75:110, 5:100]

def preprocess(img, scale_percent = 220):

    width = int(img.shape[1] * scale_percent / 100)
    height = int(img.shape[0] * scale_percent / 100)
    dim = (width, height)
    img = cv2.resize(img, dim, interpolation=cv2.INTER_AREA)

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    ret, thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)

    kernel = np.ones((2, 2), np.uint8)
    opening = cv2.morphologyEx(thresh, cv2.MORPH_OPEN, kernel, iterations=2)

    dist_transform = cv2.distanceTransform(opening, cv2.DIST_L2, 5)
    ret, sure_fg = cv2.threshold(dist_transform, 0.4*dist_transform.max(), 255, 0)

    sure_fg = np.uint8(sure_fg)

    return sure_fg


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

