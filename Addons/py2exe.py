import subprocess
import os
import time
from shutil import copy2


#Write Your file path and name
file_dir = r"C:\Users\pawel\Desktop\b"        #write direction of py file you want to make exe
file_name = "c"                                     #py file name without ".py"
dir_to_copy = r"C:\Users\pawel\Desktop\a"           #dir to copy exe file   
update_PYINSTALLER = 0                              #write "1" if you need to install pyinstaller

if 1 == update_PYINSTALLER:
    p = subprocess.Popen(["start", "cmd", "/k",
                     "pip install https://github.com/pyinstaller/pyinstaller/archive/develop.tar.gz"
                    + "&& exit"], shell = True)

#Do not touch
exe_dir = file_dir + "\\dist"                       #exe dir
p = subprocess.Popen(["start", "cmd", "/k",
                     (file_dir[0:2]) + " && " +
                     "cd " + file_dir
                     + " && pyinstaller " + file_name + ".py -F "
                     + "&& exit"],
                     shell = True)


time.sleep(55)
copy2(exe_dir + "\\" + file_name +".exe" , dir_to_copy )

