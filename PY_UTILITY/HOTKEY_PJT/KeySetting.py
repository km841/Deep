import os
import re
import sys
import keyboard
import pyperclip
from ctypes import *

keyMap = ['Q',
          'W',
          'E',
          'R',
          'T',
          'Y',
          'U',
          'I',
          'O',
          'P',
          'A',
          'S',
          'D',
          'F',
          'G',
          'H',
          'J',
          'K',
          'L',
          'Z',
          'X',
          'C',
          'V',
          'B',
          'N',
          'M',
          'F1',
          'F2',
          'F3',
          'F4',
          'F5',
          'F6',
          'F7',
          'F8',
          'F10',
          'F11',]


class NoneContentsError(Exception):
    pass

class ExistingKeyError(Exception):
    pass

class ManagementSystem:
    def __init__(self):
        self._control = {}
        self._dataPath = os.path.expanduser('~') + os.sep + 'AppData\\Roaming\\Convenience' + os.sep + 'data.bin'

    def _operating(self):
        self._control['system'] = Files()
        return self._control['system']

    def _filesBackup(self):
        if self._control['system']._files:
            operate = self._control['system']
            with open(self._dataPath, 'w', encoding='euc-kr') as fw:
                for dataTuple in operate._keyList(): fw.write(f"{dataTuple[0]}:{dataTuple[1].name},{dataTuple[1].path}\n")

        else:
            if os.path.exists(self._dataPath):
                operate_dict = self._control['system']._files
                lineReader = open(self._dataPath, 'r', encoding='euc-kr').read()
                for line in lineReader.split('\n'):
                    if line == '':
                        continue
                    backUp = line.split(':', maxsplit=1)
                    loadPath = backUp[-1].split(',')
                    if loadPath:
                        operate_dict[backUp[0]] = File(loadPath[0], loadPath[1])
                    
class Files:
    def __init__(self):
        self._files = {}
        self._functionKey = re.compile('F[1-9][0-2]?', re.IGNORECASE)
        
    def _keyList(self):
        def _functionKeyCheck(key):
            if self._functionKey.search(key): return (0, int(key[1:]))
            else: return (1, key)
            
        if self._files:
            self._items = [(key, self._files[key]) for key in sorted(self._files.keys(),
                                                                         key=_functionKeyCheck)]
            return self._items
        else: raise NoneContentsError('{}')

    def _fileAdd(self, key, name, path):
        if key in self._files:
            raise ExistingKeyError(key)
        if key not in self._files:
            self._files[key] = File(name, path)

    def _fileDel(self, key):
        if key not in self._files:
            print('\n' + f"'{key}' ????????? ???????????? ????????????")
            return False

        del self._files[key]
        print('\n' + f"'{key}' ?????? ??????.")
            
        
    def __iter__(self):
        if self._files:
            for k,v in self._files.items():
                yield (k,v.name)
        else: raise NoneContentsError('{}')

class File:
    def __init__(self, name, path):
        self.name = name
        self.path = path

    def __call__(self):
        return self.path

def userInput(*, key=False, path=False, delete=False):
    if key:
        tempInput = input("\n????????? ???????????? ???????????????\n>>>")
        if re.search('f|F[1-9][0-2]?', tempInput): tempInput = 'F' + str(tempInput[1:])
        if tempInput.isalpha(): tempInput = tempInput.upper()
        if tempInput not in keyMap:
            print("????????? ??? ?????? ??? ?????????.")
            return None
        return tempInput

    if path:
        tempInput = input("\n????????? ???????????????\n(???????????? ???????????? ????????? ?????? ????????? ??????(Ctrl+C ??? ??????)??? ???????????????)\n>>>")
        if tempInput == '': tempInput = pyperclip.paste()
        if not os.path.exists(tempInput):
            print("???????????? ?????? ???????????????.")
            return None
        return tempInput

    if delete:
        tempInput = input("\n????????? ?????? ???????????????\n>>>")
        if tempInput.isalpha(): tempInput = tempInput.upper()
        return tempInput
        
    


def main():
    dirPath = os.path.expanduser('~') + os.sep + 'AppData\\Roaming\\Convenience'
    dataPath = dirPath + os.sep + 'data.bin'
    dataFlag = True
    
    management = ManagementSystem()
    operating = management._operating()
    management._filesBackup()

    if not os.path.exists(dirPath):
        try: os.mkdir(dirPath)
        except PermissionError:
            print("?????? ?????? ????????? ????????????.")
            os.system('pause')
            sys.exit()

    if not os.path.exists(dataPath) or not(bool(os.path.getsize(dataPath))):
        dataFlag = False
        print("????????? ???????????? ????????????.\n")
        
    selectInput, pathInput, keyInput = None, None, None
    while selectInput != 'quit':
        selectInput = input("\n<?????? ??????>\n1. ????????? ??????\n2. ????????? ??? ??????\n3. ??? ??????\n('quit'??? ???????????? ???????????????.)\n>>>")
        if selectInput.isalpha(): selectInput = selectInput.lower()
        if selectInput == '1':
            while ((pathInput is None) or (keyInput is None)):
                if pathInput is None:
                    if (pathInput := userInput(path=True)) == None:
                        continue

                if keyInput is None:
                    if (keyInput := userInput(key=True)) == None:
                        continue
                    
                try:
                    operating._fileAdd(keyInput,
                                        os.path.basename(pathInput),
                                        pathInput)

                except ExistingKeyError as e:
                    print(f"'{e}'??? ?????? ????????? ????????????.\n????????? ?????? ??????????????????.")
                    keyInput = None
                    continue

                else:
                    selectInput, pathInput, keyInput = None, None, None
                    management._filesBackup()
                    os.system('cls')
                    break
                        
                    
        elif selectInput == '2':
            try:
                os.system('cls')
                for filesKey in operating._keyList():
                    print("\n{}: {}".format(filesKey[0], filesKey[1].name))
                os.system('pause')
                os.system('cls')

            except NoneContentsError:
                print("\n????????? ???????????? ????????????.")
                os.system('pause')
                os.system('cls')

        elif selectInput == '3':
            operating._fileDel(userInput(delete=True))
            management._filesBackup()
            os.system('pause')
            os.system('cls')

        os.system('cls')
            
                

if __name__ == "__main__":
    main()
                    
                        
                        
                        
                    

                
            
        
            
            
        

    
        
        
        
        
