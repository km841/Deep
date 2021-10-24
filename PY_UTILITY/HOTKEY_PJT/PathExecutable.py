import win32api
import win32con
import win32gui
import win32ui
import win32event
import win32com.client
import winerror
import subprocess
import psutil
import os
import sys
import keyboard
import winreg
import time
from timer import *
from ctypes import *
from threading import Thread
from functools import partial

hWindow = 0
MessageGenerator = set_timer
MessageBoxW = windll.user32.MessageBoxW
ShellExecuteW = windll.shell32.ShellExecuteW
CreateMutex = win32event.CreateMutex
ERROR_ALREADY_EXISTS = winerror.ERROR_ALREADY_EXISTS
WMI = win32com.client.GetObject('winmgmts:')
DISPLAY_STATUS = 'ROUTINE_STOP'
IE_STATUS = None

class File:
    def __init__(self, name, path):
        self.name = name
        self.path = path

    def __call__(self):
        return self.path

class SingleInstance:
    def __init__(self):
        self.hMutex = CreateMutex(None, False, 'PathExecutable')
        self.lastError = win32api.GetLastError

    def alreadyRunning(self):
        return (self.lastError() == ERROR_ALREADY_EXISTS)

    def __del__(self):
        if self.hMutex:
            win32api.CloseHandle(self.hMutex)

class KeyboardMessage:
    def __init__(self, data):
        self.keyStrokeManager = None
        self.dataDict = data

    def keyPressed(self, event):
        self.keyStrokeManager = str(event.name).upper()

    def keyboardInputCheck(self):
        keyboard.on_press(self.keyPressed)
        keyboard.wait()

    def messageManager(self):
        global DISPLAY_STATUS
        while 1:
            time.sleep(0.1)
            if (DISPLAY_STATUS == 'ROUTINE_STOP') and (self.keyStrokeManager == 'F9'):
                DISPLAY_STATUS = 'ROUTINE_START'
                time.sleep(0.1)
                self.keyStrokeManager = None
            elif (DISPLAY_STATUS == 'ROUTINE_START') and (self.keyStrokeManager == 'F9'):
                DISPLAY_STATUS = 'ROUTINE_STOP'
                time.sleep(0.1)
                self.keyStrokeManager = None
            elif (DISPLAY_STATUS == 'ROUTINE_START') and (self.keyStrokeManager in self.dataDict):
                if not os.path.exists(self.dataDict[self.keyStrokeManager]()):
                    MessageBoxW(None, f"저장된 경로를 찾을 수 없습니다.\n'KeySetting.exe' 파일로 '3. 키 삭제 -> '{self.keyStrokeManager}' 후 재등록 해주세요.", "ERROR: 경로을 찾지 못함", 0)
                    time.sleep(0.1)
                    self.keyStrokeManager = None
                    continue
                try: ShellExecuteW(0, 'open', self.dataDict[self.keyStrokeManager](), None, None, 1)
                except Exception: pass
                time.sleep(0.5)
                self.keyStrokeManager = None
            elif self.keyStrokeManager == 'F12': psutil.Process(os.getpid()).terminate()
                
                
def fileLoad():
    filePath = os.path.expanduser('~') + os.sep + 'AppData\\Roaming\\Convenience' + os.sep + 'data.bin'
    if os.path.exists(filePath):
        dataDict = {}
        lineReader = open(filePath, 'r', encoding='euc-kr').read()
        for line in lineReader.split('\n'):
            if line == '':
                continue
            backUp = line.split(':', maxsplit=1)
            loadPath = backUp[-1].split(',')
            dataDict[backUp[0]] = File(loadPath[0], loadPath[1])
        return dataDict
        
    else: return False

def startUpRoutine():
    with winreg.OpenKey(winreg.HKEY_LOCAL_MACHINE, "Software\Microsoft\Windows\CurrentVersion\Run") as r:
        try: winreg.SetValueEx(r, 'Convenience', 0, winreg.REG_SZ, __file__)
        except Exception: pass

def ieExitThread(get_id, time_object):
    global WMI
    time.sleep(0.1)
    pInst = WMI.instancesOf('Win32_Process')
    if (DISPLAY_STATUS == 'ROUTINE_START') and ('iexplore.exe' in [p.Properties_('Name').Value for p in pInst]):
        subprocess.call('taskkill /F /IM iexplore.exe', creationflags=0x08000000)
    
def main():
    global hWindow

    mutex = SingleInstance()
    if mutex.alreadyRunning():
        MessageBoxW(None, "이미 실행중입니다.", "ERROR: 중복 실행", 0)
        sys.exit()
        
    dataDict = fileLoad()
    if not dataDict:
        MessageBoxW(None, "데이터 파일이 존재하지 않습니다.\n'KeySetting.exe' 파일을 실행하여 키를 추가하세요", "ERROR: 데이터 파일이 존재하지 않음", 0)
        sys.exit()
        
    message = KeyboardMessage(dataDict)
    try: startUpRoutine()
    except Exception: pass
    threadRoutine = [Thread(target=routine) for routine in [message.keyboardInputCheck,
                                                            message.messageManager,]]
    for routine in threadRoutine: routine.daemon = True
    for routine in threadRoutine: routine.start()
    
    hInstance = win32api.GetModuleHandle()
    className = 'Hotkey_Project'
    getMessage = partial(MessageGenerator, 300, windowMessage)
    ieExit = partial(MessageGenerator, 200, ieExitThread)
    wndClass = win32gui.WNDCLASS()
    wndClass.style = win32con.CS_HREDRAW | win32con.CS_VREDRAW
    wndClass.lpfnWndProc = wndProc
    wndClass.hInstance = hInstance
    wndClass.hCursor = win32gui.LoadCursor(None, win32con.IDC_ARROW)
    wndClass.hbrBackground = win32gui.GetStockObject(win32con.WHITE_BRUSH)
    wndClass.lpszClassName = className
    wndClassAtom = win32gui.RegisterClass(wndClass)
    exStyle = win32con.WS_EX_COMPOSITED | win32con.WS_EX_LAYERED | win32con.WS_EX_NOACTIVATE | win32con.WS_EX_TOPMOST | win32con.WS_EX_TRANSPARENT
    style = win32con.WS_DISABLED | win32con.WS_POPUP | win32con.WS_VISIBLE

    hWindow = win32gui.CreateWindowEx(
        exStyle,
        wndClassAtom,
        None,
        style,
        0,
        0,
        win32api.GetSystemMetrics(win32con.SM_CXSCREEN),
        win32api.GetSystemMetrics(win32con.SM_CYSCREEN),
        None,
        None,
        hInstance,
        None
    )
    win32gui.SetLayeredWindowAttributes(hWindow, 0x00ffffff, 255, win32con.LWA_COLORKEY | win32con.LWA_ALPHA)
    win32gui.SetWindowPos(hWindow, win32con.HWND_TOPMOST, 0, 0, 0, 0,
        win32con.SWP_NOACTIVATE | win32con.SWP_NOMOVE | win32con.SWP_NOSIZE | win32con.SWP_SHOWWINDOW)

    ieExit()
    getMessage()
    win32gui.PumpMessages()

def windowMessage(get_id, time_object):
    global hWindow
    win32gui.InvalidateRect(hWindow, None, True)
                    

def wndProc(hWnd, message, wParam, lParam):
    if message == win32con.WM_PAINT:
        hdc, paintStruct = win32gui.BeginPaint(hWnd)
        dpiScale = win32ui.GetDeviceCaps(hdc, win32con.LOGPIXELSX) / 50.0
        fontSize = 18
        lf = win32gui.LOGFONT()
        lf.lfFaceName = "consolas"
        lf.lfHeight = int(round(dpiScale * fontSize))
        lf.lfQuality = win32con.NONANTIALIASED_QUALITY
        hf = win32gui.CreateFontIndirect(lf)
        win32gui.SelectObject(hdc, hf)
        rect = win32gui.GetClientRect(hWnd)
        
        win32gui.DrawText(
            hdc,
            (lambda message: "@ Running routine" if message == "ROUTINE_START" else "@ Stop routine")(DISPLAY_STATUS),
            -1,
            rect,
            win32con.DT_TOP | win32con.DT_NOCLIP | win32con.DT_SINGLELINE | win32con.DT_RIGHT
            )
        
        win32gui.EndPaint(hWnd, paintStruct)
        return 0

    if message == win32con.WM_DESTROY:
        win32gui.PostQuitMessage(0)
        return 0

    else:
        return win32gui.DefWindowProc(hWnd, message, wParam, lParam)


if __name__ == '__main__':
    main()
