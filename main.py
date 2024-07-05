import sys
import win32gui  # pip install pywin32
from pynput import keyboard
from threading import Thread
from win32com.client import Dispatch
import pythoncom

collected = {}


def get_windows(hd, arg):
    global collected
    if win32gui.IsWindow(hd) and win32gui.IsWindowVisible(hd) and win32gui.IsWindowEnabled(hd):
        text = win32gui.GetWindowText(hd)  # 通过句柄，获取每个窗口的标题
        if text:
            collected[hd] = text

def list_windows():
    win32gui.EnumWindows(get_windows, 0)

    for k, v in collected.items():
        print(k, v, sep=' | ')


win_dict = {
    r'<49>' : 18811026, # vscode
    r'<50>' : 7736518, # whalek
    r'<51>' : 722514 # chrome
}


def listen():  # 键盘监听函数
    print("listening")
    def on_press(key):
        print(key)

        if win_dict.get(str(key)) is not None:
            pythoncom.CoInitialize()
            shell = Dispatch("WScript.Shell")
            shell.SendKeys('%')
            win32gui.SetForegroundWindow(win_dict.get(str(key)))

        if str(key) == r'<48>':
            sys.exit()

    def on_release(key):
        print(key)

    with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
        listener.join()
        



class ListenThread(Thread):

    def __init__(self):
        super().__init__()

    def run(self):
        listen()


if __name__ == '__main__':
    list_windows()
    listenThread = ListenThread()  # 创建监听线程
    listenThread.start()