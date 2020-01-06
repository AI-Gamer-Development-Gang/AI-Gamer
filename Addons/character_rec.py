import cv2
import numpy as np

doodle = cv2.imread('doodl.png')
test = cv2.VideoCapture('aa.mp4')


while 1:

    _, frame = test.read()
    doodle_gray = cv2.cvtColor(doodle, cv2.COLOR_BGR2GRAY)
    test_gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    w, h = doodle.shape[:-1]
    res = cv2.matchTemplate(test_gray, doodle_gray, 3)

    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(res)

    #top_left = min_loc
    top_left = max_loc
    bottom_right = (top_left[0] + w, top_left[1] + h)
    cv2.rectangle(frame,top_left, bottom_right, 255, 2)

##    print(res)
##
##    w,h,x,y = cv2.minMaxLoc(res)
##    print(top_left)
##    print(bottom_right)
##    print(w)
##    print(h)



    cv2.imshow('a',frame)
    key = cv2.waitKey(5)
    if key == 27:
        break
