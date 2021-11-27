import serial
import tkinter as tk
import time

arduinoData = serial.Serial('COM3', 115200)

height = 1080
width = 1920

root = tk.Tk()

root.title('ICE MASTER 3000')
root.geometry('1920x1080')

root.attributes('-fullscreen', True)

canvas = tk.Canvas(root, height=height, width=width)
canvas.pack()
frame = tk.Frame(root, bg='#04050f')
frame.place(relwidth=1, relheight=1)

colorNormal = '#0d0e26'

mode = [0]

def MODE1():
     arduinoData.write('1'.encode())
     arduinoData.write('>'.encode())
     mode[0] = 1

def MODE2():
    arduinoData.write('2'.encode())
    arduinoData.write('>'.encode())
    mode[0] = 2

def MODE3():
    arduinoData.write('3'.encode())
    arduinoData.write('>'.encode())
    mode[0] = 3


def MODE4():
    arduinoData.write('4'.encode())
    arduinoData.write('>'.encode())
    mode[0] = 4


def MODE5():
    arduinoData.write('5'.encode())
    arduinoData.write('>'.encode())
    mode[0] = 5


def MODE6():
    arduinoData.write('6'.encode())
    arduinoData.write('>'.encode())
    mode[0] = 6


def MODE7():
    arduinoData.write('7'.encode())
    arduinoData.write('>'.encode())
    mode[0] = 7


def MODE8():
    arduinoData.write('8'.encode())
    arduinoData.write('>'.encode())
    mode[0] = 8


def MODE9():
    arduinoData.write('9'.encode())
    arduinoData.write('>'.encode())
    mode[0] = 9


def MODE10():
    arduinoData.write('10'.encode())
    arduinoData.write('>'.encode())
    mode[0] = 10
    print("Activated")

def MODE11():
    arduinoData.write('11'.encode())
    arduinoData.write('>'.encode())
    mode[0] = 11
    print("Activated")

def MODE12():
    arduinoData.write('12'.encode())
    arduinoData.write('>'.encode())
    mode[0] = 11
    print("Activated")

MODE1 = tk.Button(frame, text="PAUSE", command=MODE1, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE1.place(anchor='nw', x=100, y=100, width=265, height=75)

MODE2 = tk.Button(frame, text="RAINBOW", command=MODE2, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE2.place(anchor='nw', x=100 + 1*290, y=100, width=265, height=75)

MODE3 = tk.Button(frame, text="CLOUD", command=MODE3, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE3.place(anchor='nw', x=100 + 2*290, y=100, width=265, height=75)

MODE4 = tk.Button(frame, text="LAVA", command=MODE4, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE4.place(anchor='nw', x=100 + 3*290, y=100, width=265, height=75)

MODE5 = tk.Button(frame, text="FORREST", command=MODE5, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE5.place(anchor='nw', x=100 + 4*290, y=100, width=265, height=75)

MODE6 = tk.Button(frame, text="OCEAN", command=MODE6, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE6.place(anchor='nw', x=100 + 5*290, y=100, width=265, height=75)

MODE7 = tk.Button(frame, text="STROBE 25%", command=MODE7, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE7.place(anchor='nw', x=100 + 0*290, y=200, width=265, height=75)

MODE8 = tk.Button(frame, text="STROBE 50%", command=MODE8, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE8.place(anchor='nw', x=100 + 1*290, y=200, width=265, height=75)

MODE9 = tk.Button(frame, text="STROBE 100%", command=MODE9, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE9.place(anchor='nw', x=100 + 2*290, y=200, width=265, height=75)

MODE10 = tk.Button(frame, text="DROP 1", command=MODE10, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE10.place(anchor='nw', x=100 + 3*290, y=200, width=265, height=75)

MODE11 = tk.Button(frame, text="DROP 2", command=MODE11, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE11.place(anchor='nw', x=100 + 4*290, y=200, width=265, height=75)

MODE12 = tk.Button(frame, text="DROP 3", command=MODE12, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE12.place(anchor='nw', x=100 + 5*290, y=200, width=265, height=75)


def BPM1():
    arduinoData.write('91'.encode())
    arduinoData.write('>'.encode())

def BPM2():
    arduinoData.write('92'.encode())
    arduinoData.write('>'.encode())

def BPM3():
    arduinoData.write('93'.encode())
    arduinoData.write('>'.encode())

def BPM4():
    arduinoData.write('94'.encode())
    arduinoData.write('>'.encode())

def BPM5():
    arduinoData.write('95'.encode())
    arduinoData.write('>'.encode())

def BPM6():
    arduinoData.write('96'.encode())
    arduinoData.write('>'.encode())

def BPM7():
    arduinoData.write('97'.encode())
    arduinoData.write('>'.encode())

def BPM8():
    arduinoData.write('98'.encode())
    arduinoData.write('>'.encode())

def BPM9():
    arduinoData.write('99'.encode())
    arduinoData.write('>'.encode())


BPM1 = tk.Button(frame, text="BPM 100", command=BPM1, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM1.place(anchor='nw', x=100, y=300, width=265, height=75)

BPM2 = tk.Button(frame, text="BPM 110", command=BPM2, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM2.place(anchor='nw', x=100 + 1*290, y=300, width=265, height=75)

BPM3 = tk.Button(frame, text="BPM 120", command=BPM3, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM3.place(anchor='nw', x=100 + 2*290, y=300, width=265, height=75)

BPM4 = tk.Button(frame, text="BPM 125", command=BPM4, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM4.place(anchor='nw', x=100 + 3*290, y=300, width=265, height=75)

BPM5 = tk.Button(frame, text="BPM 128", command=BPM5, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM5.place(anchor='nw', x=100 + 4*290, y=300, width=265, height=75)

BPM6 = tk.Button(frame, text="BPM 130", command=BPM6, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM6.place(anchor='nw', x=100 + 5*290, y=300, width=265, height=75)

BPM7 = tk.Button(frame, text="BPM 132", command=BPM7, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM7.place(anchor='nw', x=100 + 0*290, y=400, width=265, height=75)

BPM8 = tk.Button(frame, text="BPM 140", command=BPM8, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM8.place(anchor='nw', x=100 + 1*290, y=400, width=265, height=75)

BPM9 = tk.Button(frame, text="BPM 150", command=BPM9, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM9.place(anchor='nw', x=100 + 2*290, y=400, width=265, height=75)



root.bind('<Escape>', lambda e: root.destroy())

while True:
    root.update()
