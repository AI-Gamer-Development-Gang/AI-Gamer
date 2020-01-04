import gym
from gym import error, spaces, utils
from gym.utils import seeding

from subprocess import Popen,PIPE
import time

import pyautogui
import pygetwindow as gw


class doodle_env(gym.Env):
    metadata = {'render.modes': ['human']}
    reward_range = (float(0), float(1))

    def gameboot(path='C:\\Users\\tomek\\source\\repos\\Project14\\Release\\Project14.exe'):
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

    def __init__(self):
        self.action_space = spaces.Discrete(2) #LEFT or RIGHT
        self.observation_space = spaces.Tuple((spaces.Discrete(2), #each discrete space for each platform coordinates
                                               spaces.Discrete(2), #IT CAN BE A PICTURE INSTEAD
                                               spaces.Discrete(2),
                                               spaces.Discrete(2),
                                               spaces.Discrete(2),
                                               spaces.Discrete(2),
                                               spaces.Discrete(2),
                                               spaces.Discrete(2),
                                               spaces.Discrete(2),
                                               spaces.Discrete(2)))

        self.gameboot()
        self.win_pos_X, self.win_pos_Y = self.mouseset()
        self.actions('start_game', self.win_pos_X, self.win_pos_Y)
        self.actions('pause', self.win_pos_X, self.win_pos_Y)


    def step(self, action):
        self.actions('unpause', self.win_pos_X, self.win_pos_Y)
        # take action
        self.actions('pause', self.win_pos_X, self.win_pos_Y)
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

    def action(self):
        # map action_space to real action only (???)
        pass

    # def observation(self): #OBSERVATION SHOULD BE A VARIABLE NOT A METHOD
        # pass

