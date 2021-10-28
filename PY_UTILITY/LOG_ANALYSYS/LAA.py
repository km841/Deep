import os
import re
import tempfile
import shutil
import datetime
import tkinter.ttk as ttk
from tkinter import *
from tkinter import filedialog
from tkinter import font

# Barcode Types
completed_prod = list()
noRead_prod = list()
invoiceNoRead_prod = list()
campNoRead_prod = list()
other_prod=list()

# Searching Variable
searching_prod = set()

# Data Type Sorting
dataMatching = {
        'completed':completed_prod,
        'noRead':noRead_prod,
        'invoiceCode':invoiceNoRead_prod,
        'campCode':campNoRead_prod,
        'other':other_prod,
        }

# Product Total Count
total_product = 0

# Casting Function ( 2021, 3, 7 -> 20210307 )
def timeCasting(year, month, day):
    m, d = str(month), str(day)

    if len(m) < 2:
        m = '0' + m

    if len(d) < 2:
        d = '0' + d

    return ''.join([str(year), m, d])

# Days List
daysList = list()
timeObject = datetime.datetime.now()

for idx in range(0, 11):
    current = timeObject - datetime.timedelta(idx)
    daysList.append(timeCasting(current.year,
                                current.month,
                                current.day))

# Invoice Code Searching
def searching():
    
    # Global Data
    global searching_prod
    searching_prod.clear()
    
    word = searching_input_entry.get()
    if not word.isdigit() or len(word) != 4:
        error_message_lbl.config(text='Error : 검색어 확인 요함', fg='red')
        
        if saveBtn['state'] == NORMAL:
            saveBtn['state'] = DISABLED
            
        return

    # Regex
    expression = eval("re.compile(r'102\\d{5,7}%s[,;\\n]')" % word)

    # Data Collection
    for root, _, files in os.walk(os.getcwd()):
        for file in files:
            if (searching_combobox.get() in file) and \
                file.split('.')[-1] in ['txt', 'csv']:

                try:
                    contents = open(
                        os.path.join(root, file),
                        mode='r',
                        encoding='euc-kr',
                        errors='replace'
                        ).read()

                except PermissionError:
                    continue

                if not contents:
                    continue

                values = expression.finditer(contents)
                if not values:
                    continue
                
                for value in values:
                    start = contents[:value.start()].rfind('\n')
                    end = contents[value.end():].find('\n')

                    # Data Filter
                    if end > 10:
                        end = 0

                    try:
                        searching_prod.add(contents[start:value.end()+end].replace('\n', '').replace('\"', ""))

                    # if Last locate
                    except IndexError:
                        searching_prod.add(contents[start:value.end()].replace('\n', '').replace('\"', ""))

                    # File Pointer Initialize
                    finally:
                        start, end = 0, 0
    
    lstbox.delete(0, END)
    lstbox.insert(0, *sorted(list(searching_prod), reverse = True))

    contents_lbl_value.config(text=f'{len(searching_prod)}/ -')
    error_message_lbl.config(text='')
    
    if lstbox.size():
        saveBtn['state'] = NORMAL

    else:
        saveBtn['state'] = DISABLED

# Log File Processing
def logAnalysis(txt):

    # Global Data
    global completed_prod
    global noRead_prod
    global invoiceNoRead_prod
    global campNoRead_prod
    global other_prod
    global total_product
    
    #Log Parsing & Analysis
    completed = re.compile(#blind)

    hanjinCode = re.compile(#blind)
    campCode = re.compile(#blind)
    InvoiceCode = re.compile(#blind)
    
    # if not str.startswith...
    # 1. Trigger ON!!! ...
    # 2. Trigger OFF!!! ...
    # 3. TrayID input>>>> ...
        
        #'noread':re.compile(), if Completed -> Append
        #'invoice':re.compile(), # if not Completed -> elif Camp Code -> if not Invoice Code -> Append
        #'camp':re.compile(), # if not Completed -> elif Camp Code -> Append

    # Temp Folder Create & log File Copy 
    with tempfile.TemporaryDirectory() as td:
        temp_txt = os.path.join(td, os.path.basename(txt))
        contents = None
        
        try:
            shutil.copy(txt, temp_txt)
            
        except PermissionError:
            return
            #File에 대한 권한이 없으므로 RETURN
        
        else:
            if os.path.exists(temp_txt):
                with open(
                    temp_txt, 
                    mode = 'r', 
                    encoding = 'euc-kr', 
                    errors = 'replace') as f:
                    
                    contents = f.readlines()
                    
            else:
                return
                #File에 대한 주소가 없으므로 RETURN
            
        if not contents:
            return
            #File에 내용이 없으므로 RETURN

    # Data Initialize
    completed_prod.clear()
    noRead_prod.clear()
    invoiceNoRead_prod.clear()
    campNoRead_prod.clear()
    other_prod.clear()

    total_product = 0

    for content in contents:
        content = content.replace('\n', '')

        try:
            barcode = content.split('\t', maxsplit=1)[1]
            
        except IndexError:
            other_prod.append(content) # Other
            continue
        
        if barcode.startswith('Trigger') or barcode.startswith('TrayID'):
            continue

        total_product += 1

        if completed.search(barcode): # Completed
            completed_prod.append(content)

        elif campCode.search(barcode) and not InvoiceCode.search(barcode):
            invoiceNoRead_prod.append(content) # Invoice No Read

        elif InvoiceCode.search(barcode):
            campNoRead_prod.append(content) # Camp Code No Read
            
        else: # No Read
            noRead_prod.append(content) # No Read 
            

def fileOpenDialog():
    log_file = filedialog.askopenfilename(title = '로그 파일을 선택해주세요',
                                        filetypes = (('csv 파일', '*.csv'),
                                                   ('txt 파일', '*.txt')),
                                        initialdir = os.getcwd())

    if not log_file:
            return

    input_entry.delete(0, END)
    input_entry.insert('0', log_file)

def fileSaveDialog():
    file = filedialog.asksaveasfile(title = '저장할 파일 경로를 지정해주세요',
                                      mode = 'w',
                                  defaultextension = ".csv",
                                      filetypes = (('csv 파일', '*.csv'),
                                                   ('txt 파일', '*.txt')))
                                                   
    if file is None: # Cancel Button Click
        return

    data = lstbox.get(0, lstbox.size()-1)
    if not data:
        file.write('')
        file.close()

    for line in data:
        file.write(line)
        file.write('\n')

    file.close()
    

def completed_cmd():
    lstbox.delete(0, END)
    lstbox.insert(0, *completed_prod)
    contents_lbl_value.config(text=f'{len(completed_prod)} / {total_product}')

    if lstbox.size():
        saveBtn['state'] = NORMAL

    else:
        saveBtn['state'] = DISABLED
    

def noRead_cmd():
    lstbox.delete(0, END)
    lstbox.insert(0, *noRead_prod)
    contents_lbl_value.config(text=f'{len(noRead_prod)} / {total_product}')

    if lstbox.size():
        saveBtn['state'] = NORMAL

    else:
        saveBtn['state'] = DISABLED
    

def invoiceCode_cmd():
    lstbox.delete(0, END)
    lstbox.insert(0, *invoiceNoRead_prod)
    contents_lbl_value.config(text=f'{len(invoiceNoRead_prod)} / {total_product}')

    if lstbox.size():
        saveBtn['state'] = NORMAL

    else:
        saveBtn['state'] = DISABLED


def campCode_cmd():
    lstbox.delete(0, END)
    lstbox.insert(0, *campNoRead_prod)
    contents_lbl_value.config(text=f'{len(campNoRead_prod)} / {total_product}')

    if lstbox.size():
        saveBtn['state'] = NORMAL

    else:
        saveBtn['state'] = DISABLED
    
    
def other_cmd():
    lstbox.delete(0, END)
    lstbox.insert(0, *other_prod)
    contents_lbl_value.config(text=f'{len(other_prod)} / -')

    if lstbox.size():
        saveBtn['state'] = NORMAL

    else:
        saveBtn['state'] = DISABLED


# Start Button Click
def run():
    global dataMatching
    
    # Input Data Check ( Empty )
    if not input_entry.get():
        error_message_lbl.config(text='Error : 로그 파일 주소 누락', fg='red')
        
        if saveBtn['state'] == NORMAL:
            saveBtn['state'] = DISABLED
            
        return
    
    # Input Data Check ( Path )
    elif not os.path.exists(input_entry.get()) or \
        os.path.isdir(input_entry.get()) or \
        input_entry.get().rsplit('.', maxsplit=1)[-1] not in ['csv', 'txt']:

        error_message_lbl.config(text='Error : 로그 파일 주소 확인 요함', fg='red')
            
        if saveBtn['state'] == NORMAL:
            saveBtn['state'] = DISABLED

        return

    # Error Message Initialize
    error_message_lbl.config(text='')
    
    # Log Analysis
    logAnalysis(input_entry.get())

    lstbox.delete(0, END)
    lstbox.insert(0, *dataMatching[choice_var.get()])
    
    # Other Type Q'Ty
    if choice_var.get() == 'other':
        contents_lbl_value.config(text = f'{len(dataMatching[choice_var.get()])} / -')

    else:
        contents_lbl_value.config(text = f'{len(dataMatching[choice_var.get()])} / {total_product}')

    saveBtn['state'] = NORMAL
    

# Create Window
root = Tk()
root.title('Log Analysis Automation')
root.geometry('820x780')

logo_font = font.Font(root,
                    family = 'Cambria',
                    size = 30,
                    weight = 'bold')

btn_font = font.Font(root,
                    family = 'Cambria',
                    size = 9,
                    weight = 'bold')

lbl_font = font.Font(root,
                    family = 'Cambria',
                    size = 10,
                    weight = 'bold')
                    
style = ttk.Style()
style.configure("Bold.TLabel", font = ("Consolas", 12, 'bold'))

# Main Frame ( Frame )
main_frame = Frame(root)
main_frame.pack()

## Title Frame ( Label Frame )
title_frame = Frame(main_frame)
title_frame.pack()

### Title Label
title_label = Label(title_frame, text = 'Log  Analysis  Automation', anchor = 'center')
title_label['font'] = logo_font
title_label.pack(side='top', pady=25)

## Input Frame ( Entry , Button )
input_frame = Frame(main_frame)
input_frame.pack()

### Input Entry
input_entry = Entry(input_frame, width=100)
input_entry.pack(side='left', ipady=4, padx=4, pady=5)

### Input Button
input_button = Button(input_frame, text='Find', width=10, command=fileOpenDialog)
input_button.pack(side='left', padx=5, pady=5)

## Choice & List Box Frame ( Frame )
choice_lstBox_frame = Frame(main_frame)
choice_lstBox_frame.pack(fill='y')

### Choice & Searching Frame
choice_searching_frame = Frame(choice_lstBox_frame)
choice_searching_frame.pack(side='left', fill='y')

### Choice Frame ( Frame )
choice_lbl = ttk.Label(text='Type', style='Bold.TLabel')
choice_frame = LabelFrame(choice_searching_frame, labelwidget=choice_lbl)
choice_frame.pack(side='top', fill='both', expand=True, ipady=30)
choice_var = StringVar()

#### Completed Frame ( Radio Button )
completed_frame = Frame(choice_frame)
completed_frame.pack()
completed_btn = Radiobutton(completed_frame, text='Completed', value='completed', variable=choice_var, command=completed_cmd)
completed_btn.select()

#### No Read Frame ( Radio Button )
noRead_frame = Frame(choice_frame)
noRead_frame.pack()
noRead_btn = Radiobutton(noRead_frame, text='No Read', value='noRead', variable=choice_var, command=noRead_cmd)

#### InVoiceCode No Read Frame ( Radio Button )
invoiceCode_frame = Frame(choice_frame)
invoiceCode_frame.pack()
invoiceCode_btn = Radiobutton(invoiceCode_frame, text='Invoice Code No Read', value='invoiceCode', variable=choice_var, command=invoiceCode_cmd)

#### CampCode No Read Frame ( Radio Button )
campCode_frame = Frame(choice_frame)
campCode_frame.pack()
campCode_btn = Radiobutton(campCode_frame, text='Camp Code No Read', value='campCode', variable=choice_var, command=campCode_cmd)

#### Other Frame ( Radio Button )
other_frame = Frame(choice_frame)
other_frame.pack()
other_btn = Radiobutton(other_frame, text='Other', value='other', variable=choice_var, command=other_cmd)

completed_btn.pack(side='left', padx=30, ipady=10)
noRead_btn.pack(side='left', padx=30, ipady=10)
invoiceCode_btn.pack(side='left', padx=30, ipady=10)
campCode_btn.pack(side='left', padx=30, ipady=10)
other_btn.pack(side='left', padx=30, ipady=10)

#### Searching Frame ( Entry , Button )
searching_lbl = ttk.Label(text='Search', style='Bold.TLabel')
searching_frame = LabelFrame(choice_searching_frame, labelwidget=searching_lbl)
searching_frame.pack(side='bottom')

##### Searching Combo Box Frame ( ComboBox )
searching_combobox_frame = Frame(searching_frame)
searching_combobox_frame.pack()

###### Searching Combo Box
searching_combobox = ttk.Combobox(searching_combobox_frame, width=26, values=daysList, state='readonly')
searching_combobox.current(0)
searching_combobox.pack()

### Searching Input Frame
searching_input_frame = Frame(searching_frame)
searching_input_frame.pack()

#### Searching Input Entry
searching_input_entry = Entry(searching_input_frame, width=22)
searching_input_entry.pack(side='left', ipady=4, padx=4, pady=5)
searching_input_entry.insert(0, 'Last 4 digits')

#### Searching Input Button
searching_input_button = Button(searching_input_frame, text = 'Search', command=searching)
searching_input_button.pack(side='right')

### List Box Frame ( ListBox , Scrollbar )
lstBox_lbl = ttk.Label(text='Result', style='Bold.TLabel')
lstBox_frame = LabelFrame(choice_lstBox_frame, labelwidget=lstBox_lbl)
lstBox_frame.pack(side='right')

#### Scrollbar
lstBox_scrollbar = Scrollbar(lstBox_frame)
lstBox_scrollbar.pack(side='right', fill='y')

#### List Box
lstbox = Listbox(lstBox_frame, width=80, height=30, yscrollcommand=lstBox_scrollbar.set)
lstbox.pack(side='left', fill='y', expand=True, ipady=20)
lstBox_scrollbar.config(command=lstbox.yview)

### Run Button & Contents Frame
runBtn_contents_frame = Frame(main_frame)
runBtn_contents_frame.pack(fill='x')

#### Run Button Frame ( Button )
runBtn_frame = Frame(runBtn_contents_frame)
runBtn_frame.pack(side='left', fill='x')

##### Run Button
runBtn = Button(runBtn_frame, text='S t a r t', width=29, height=2, command=run)
runBtn['font']=btn_font
runBtn.pack(side='left')

#### Contents Frame ( Label 1, Label 2 )
contents_frame = Frame(runBtn_contents_frame)
contents_frame.pack(pady=10)

##### Contents Label ( Name )
contents_lbl_name = Label(contents_frame, text='Quantity ( Type / Total ) :')
contents_lbl_name['font'] = lbl_font
contents_lbl_name.pack(side='left')

##### Contents Label ( Value )
contents_lbl_value = Label(contents_frame, text='-')
contents_lbl_value['font'] = lbl_font
contents_lbl_value.pack(side='right')

### Save Button Frame ( Button )
saveBtn_frame = Frame(main_frame)
saveBtn_frame.pack(side='left', fill='x')

#### Save Button
saveBtn = Button(saveBtn_frame, text='S a v e', width=29, height=2, state=DISABLED, command=fileSaveDialog)
saveBtn['font'] = btn_font
saveBtn.pack()

### Error Message Frame ( Label )
error_message_frame = Frame(main_frame)
error_message_frame.pack()

#### Error Message Label
error_message_lbl = Label(error_message_frame, text='')
error_message_lbl.pack()

## Progress - Frame ( Progress Bar )
#progress_lbl = ttk.Label(text='Progress', style='Bold.TLabel')
#progress_frame = LabelFrame(root, labelwidget=progress_lbl)
#progress_frame.pack(fill='x', expand=True, padx=18)

### Progress - Progress Bar
#p_var = DoubleVar()
#progress_bar = ttk.Progressbar(progress_frame, maximum=100, variable=p_var)
#progress_bar.pack(side='bottom', fill='x', padx=5, pady=5)

root.mainloop()
