from subprocess import Popen
import time

import pyautogui
import pygetwindow as gw

import pyscreenshot

import keyboard

#import reward_detection as rd

import cv2

import numpy as np

import time

def gameboot(path='C:\\Users\\tomek\\source\\repos\\Project14\\Release\\Project14.exe'):
    Popen([path])
    time.sleep(1)


def mouseset():
    y = gw.getAllTitles()
    if 'Doodle Game!' in y:
        this = gw.getWindowsWithTitle(r'Doodle Game!')[0].topleft
        pyautogui.moveTo(this.x, this.y)
        return this.x, this.y


def get_img(win_pos_x, win_pos_y):
    img = pyscreenshot.grab(bbox=(win_pos_x, win_pos_y, win_pos_x + 440, win_pos_y + 530))
    img = np.array(img)
    img = img[75:105, 10:100]
    return img


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
    
    #mask = cv2.inRange(hsv_img, hsv_lightgreen, hsv_darkgreen)
    mask = cv2.inRange(hsv_img, (36, 0, 0), (70, 255,255))
    #mask = cv2.bitwise_not(mask, mask)
    res = cv2.bitwise_and(img, img, mask=mask)
    #hsv = cv2.cvtColor(res, cv2.COLOR_HSV2BGR)
    return res
    '''
    gray = cv2.cvtColor(res, cv2.COLOR_BGR2GRAY)
    ret, thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)

    kernel = np.ones((2, 2), np.uint8)
    opening = cv2.morphologyEx(thresh, cv2.MORPH_OPEN, kernel, iterations=2)
    
    
    return opening
    '''


if __name__ == '__main__':
    
    gameboot()
    x, y = mouseset()
    imgs = np.zeros(shape=(0,32,32))
    labels = []

    while(not keyboard.is_pressed('s')):

        if keyboard.is_pressed('p'):
            time.sleep(0.3)
            img = get_img(x, y)
            img = preprocess(img)
            cv2.imshow("", img)
            cv2.waitKey(1)
    '''
            img = rd.extract_digits(img)
            imgs = np.append(imgs, img, axis = 0)
            
    np.save('imgs', imgs)        
    
    imgs = np.load('imgs.npy', mmap_mode = 'r')
    imgs.shape
    labels = []#TEMP
    
    for i in range(imgs.shape[0]):
        cv2.imshow("", imgs[i])
        cv2.waitKey(1)
        label = input('write a label')
        
    
        labels.append(input())

    labels = np.asarray(labels)
    data = [imgs, labels]
    data = np.asarray(data)
    np.save('data', data)
    '''
