import gym
from gym import error, spaces, utils
from gym.utils import seeding

from subprocess import Popen,PIPE
import time

import pyautogui
import pygetwindow as gw

import pyscreenshot
import cv2


class doodle_env(gym.Env):
    metadata = {'render.modes': ['human']}
    reward_range = (float(0), float(1))

    def gameboot(self, path='C:\\Users\\tomek\\source\\repos\\Project14\\Release\\Project14.exe'):
        proc = Popen([path])
        time.sleep(1)

    def mouseset(self):
        y = gw.getAllTitles()
        if 'Doodle Game!' in y:
            this = gw.getWindowsWithTitle(r'Doodle Game!')[0].topleft
            pyautogui.moveTo(this.x, this.y)
            return this.x, this.y

    def actions(self, win_pos_X, win_pos_Y, to_perform='wait'):
        if to_perform == 'wait':
            time.sleep(0.1)
        elif to_perform == 'start_game':
            pyautogui.mouseDown(x=win_pos_X + 220, y=win_pos_Y + 294);
            time.sleep(1)
            pyautogui.mouseUp()
        elif to_perform == 'exit':
            pyautogui.mouseDown(x=win_pos_X + 220, y=win_pos_Y + 494);
            time.sleep(1)
            pyautogui.mouseUp()
        elif to_perform == 'try_again':
            pyautogui.mouseDown(x=win_pos_X + 220, y=win_pos_Y + 404);
            time.sleep(1)
            pyautogui.mouseUp()
        elif to_perform == 'go_left':
            pyautogui.keyDown('left')
            time.sleep(1)
            pyautogui.keyUp('left')
        elif to_perform == 'go_right':
            pyautogui.keyDown('right')
            time.sleep(1)
            pyautogui.keyUp('right')
        elif to_perform == 'pause':
            pyautogui.keyDown('space')
            time.sleep(1)
            pyautogui.keyUp('space')
        elif to_perform == 'unpause':
            pyautogui.keyDown('space')
            time.sleep(1)
            pyautogui.keyUp('space')

    def reward_detection(self, img):
        img = cv2.imread(img)
        crop_img = img[75:105, 0:100]   # img cut
        #cv2.imshow("cropped", crop_img)
        #   detection evry number on crop_img
        #   recognizing them (ML)





    def __init__(self):
        self.action_space = spaces.Discrete(3)  # LEFT or RIGHT or WAIT
        self.observation_space = spaces.Tuple((spaces.Discrete(2),  # each discrete space for each platform coordinates
                                               spaces.Discrete(2),  # IT CAN BE A PICTURE INSTEAD
                                               spaces.Discrete(2),
                                               spaces.Discrete(2),
                                               spaces.Discrete(2),
                                               spaces.Discrete(2),
                                               spaces.Discrete(2),
                                               spaces.Discrete(2),
                                               spaces.Discrete(2),
                                               spaces.Discrete(2)))
        self.reward = 0

        self.gameboot()
        self.win_pos_X, self.win_pos_Y = self.mouseset()
        self.actions('start_game', self.win_pos_X, self.win_pos_Y)
        self.actions('pause', self.win_pos_X, self.win_pos_Y)


    def step(self, action):
        self.actions('unpause', self.win_pos_X, self.win_pos_Y)

        if self.action_space[0]:                                                # map action_space to real action
            self.actions('left', self.win_pos_X, self.win_pos_Y)                # take action
        elif self.action_space[1]:
            self.actions('right', self.win_pos_X, self.win_pos_Y)
        elif self.action_space[2]:
            self.actions('wait', self.win_pos_X, self.win_pos_Y)

        self.actions('pause', self.win_pos_X, self.win_pos_Y)

        img = pyscreenshot.grab(bbox=(self.win_pos_X, self.win_pos_Y, self.win_pos_X + 440, self.win_pos_Y + 530))

        img = img[75:110, 5:100]

        scale_percent = 220  # percent of original size
        width = int(img.shape[1] * scale_percent / 100)
        height = int(img.shape[0] * scale_percent / 100)
        dim = (width, height)
        img = cv2.resize(img, dim, interpolation=cv2.INTER_AREA)
        # TODO:
        # - reward extraction
        #   1. cutting part of image which consist a reward DONE
        #   2. conversion img to arr DONE
        #   3. digit detection
        #   4. digit recognition
        #   5. making number from these digits ^
        #   6. return number
        # - platform coordinates extraction // conversion img to np arr == OBSERVATIONS
        # - deleting img from folder (obs)


        # *magic* extraction of reward and platform coordinates
        # obs might be a screen but reward must be an integer

        # return obs, rew, done, info
        pass

    def reset(self):
        pass

    def render(self):
        # info
        # smth like [reward; smth; smth]
        # game window is the other thing
        pass

    def close(self):
        pass

    '''
    def action(self): # NO IDEA
        pass

    def observation(self): #OBSERVATION SHOULD BE A VARIABLE NOT A METHOD
        pass
    '''
