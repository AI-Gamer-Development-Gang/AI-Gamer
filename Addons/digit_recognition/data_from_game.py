from subprocess import Popen
import time

import pyautogui
import pygetwindow as gw

import pyscreenshot

import keyboard

import reward_detection as rd

import cv2

import numpy as np


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
    img = img[75:110, 5:100]
    return img


if __name__ == '__main__':

    gameboot()
    x, y = mouseset()
    imgs = []
    labels = []

    while(not keyboard.is_pressed('s')):

        if keyboard.is_pressed('p'):
            img = get_img(x, y)
            img = rd.preprocess(img)
            imgs = rd.extract_digits(img)
            
            for img in imgs:        #here is a problem
                imgs.append(img)

    imgs = np.asarray(imgs)

    for img in imgs:
        cv2.imshow("cropped2", img)
        labels.append(input())

    labels = np.asarray(labels)
    data = [imgs, labels]
    data = np.asarray(data)
    np.save('data', data)
