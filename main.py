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

SPEEDLABEL = tk.Label(frame, text="ACTION", bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
SPEEDLABEL.place(anchor='nw', x=100+172*0, y=225, width=172, height=100)

def MODE50():  ## WHITE
    arduinoData.write('50'.encode())
    arduinoData.write('>'.encode())

def MODE51():  ## WHITE
    arduinoData.write('51'.encode())
    arduinoData.write('>'.encode())
def MODE60():  ## WHITE
    arduinoData.write('1'.encode())
    arduinoData.write('>'.encode())
def MODE52():  ## RED
    arduinoData.write('7'.encode())
    arduinoData.write('>'.encode())
def MODE53():  ## GREEN
    arduinoData.write('8'.encode())
    arduinoData.write('>'.encode())
def MODE54():
    arduinoData.write('9'.encode())
    arduinoData.write('>'.encode())
def MODE55():
    arduinoData.write('5'.encode())
    arduinoData.write('>'.encode())
def MODE56():
    arduinoData.write('6'.encode())
    arduinoData.write('>'.encode())
def MODE57():
    arduinoData.write('2'.encode())
    arduinoData.write('>'.encode())
def MODE58():
    arduinoData.write('3'.encode())
    arduinoData.write('>'.encode())
def MODE59():
    arduinoData.write('4'.encode())
    arduinoData.write('>'.encode())

MODE51 = tk.Button(frame, text="FANCY PANCY 2", command=MODE51, bg=colorNormal, fg='pink', font=("Arial", 14, "bold"), bd=0)
MODE51.place(anchor='nw', x=100+172*2, y=100, width=172, height=100)

MODE51 = tk.Button(frame, text="FANCY PANCY", command=MODE50, bg=colorNormal, fg='pink', font=("Arial", 14, "bold"), bd=0)
MODE51.place(anchor='nw', x=100+172*1, y=100, width=172, height=100)

MODE51 = tk.Button(frame, text="BLACKOUT", command=MODE60, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE51.place(anchor='nw', x=100+172*1, y=225, width=172, height=100)

MODE52 = tk.Button(frame, text="SLOW STROBE", command=MODE52, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE52.place(anchor='nw', x=100+172*2, y=225, width=172, height=100)

MODE53 = tk.Button(frame, text="MED STROBE", command=MODE53, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE53.place(anchor='nw', x=100+172*3, y=225, width=172, height=100)

MODE54 = tk.Button(frame, text="FAST STROBE", command=MODE54, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE54.place(anchor='nw', x=100+172*4, y=225, width=172, height=100)

MODE55 = tk.Button(frame, text="DROP 1", command=MODE55, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE55.place(anchor='nw', x=100+172*5, y=225, width=172, height=100)

MODE56 = tk.Button(frame, text="DROP 2", command=MODE56, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE56.place(anchor='nw', x=100+172*6, y=225, width=172, height=100)

MODE57 = tk.Button(frame, text="DROP 3", command=MODE57, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE57.place(anchor='nw', x=100+172*7, y=225, width=172, height=100)

MODE58 = tk.Button(frame, text="DROP 4", command=MODE58, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE58.place(anchor='nw', x=100+172*8, y=225, width=172, height=100)

MODE59 = tk.Button(frame, text="DROP 5", command=MODE59, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE59.place(anchor='nw', x=100+172*9, y=225, width=172, height=100)



SPEEDLABEL = tk.Label(frame, text="DYNAMIC", bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
SPEEDLABEL.place(anchor='nw', x=100+172*0, y=475, width=172, height=100)

def MODE41():  ## WHITE
    arduinoData.write('41'.encode())
    arduinoData.write('>'.encode())
def MODE42():  ## RED
    arduinoData.write('42'.encode())
    arduinoData.write('>'.encode())
def MODE43():  ## GREEN
    arduinoData.write('43'.encode())
    arduinoData.write('>'.encode())
def MODE44():
    arduinoData.write('44'.encode())
    arduinoData.write('>'.encode())
def MODE45():
    arduinoData.write('45'.encode())
    arduinoData.write('>'.encode())
def MODE46():
    arduinoData.write('46'.encode())
    arduinoData.write('>'.encode())
def MODE47():
    arduinoData.write('47'.encode())
    arduinoData.write('>'.encode())
def MODE48():
    arduinoData.write('48'.encode())
    arduinoData.write('>'.encode())
def MODE49():
    arduinoData.write('49'.encode())
    arduinoData.write('>'.encode())


MODE41 = tk.Button(frame, text="WHITE", command=MODE41, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE41.place(anchor='nw', x=100+172*1, y=475, width=172, height=100)

MODE42 = tk.Button(frame, text="RED", command=MODE42, bg=colorNormal, fg='red', font=("Arial", 14, "bold"), bd=0)
MODE42.place(anchor='nw', x=100+172*2, y=475, width=172, height=100)

MODE43 = tk.Button(frame, text="ORANGE", command=MODE43, bg=colorNormal, fg='orange', font=("Arial", 14, "bold"), bd=0)
MODE43.place(anchor='nw', x=100+172*3, y=475, width=172, height=100)

MODE44 = tk.Button(frame, text="YELLOW", command=MODE44, bg=colorNormal, fg='yellow', font=("Arial", 14, "bold"), bd=0)
MODE44.place(anchor='nw', x=100+172*4, y=475, width=172, height=100)

MODE45 = tk.Button(frame, text="GREEN", command=MODE45, bg=colorNormal, fg='green', font=("Arial", 14, "bold"), bd=0)
MODE45.place(anchor='nw', x=100+172*5, y=475, width=172, height=100)

MODE46 = tk.Button(frame, text="CYAN", command=MODE46, bg=colorNormal, fg='cyan', font=("Arial", 14, "bold"), bd=0)
MODE46.place(anchor='nw', x=100+172*6, y=475, width=172, height=100)

MODE47 = tk.Button(frame, text="BLUE", command=MODE47, bg=colorNormal, fg='blue', font=("Arial", 14, "bold"), bd=0)
MODE47.place(anchor='nw', x=100+172*7, y=475, width=172, height=100)

MODE48 = tk.Button(frame, text="PURPLE", command=MODE48, bg=colorNormal, fg='purple', font=("Arial", 14, "bold"), bd=0)
MODE48.place(anchor='nw', x=100+172*8, y=475, width=172, height=100)

MODE49 = tk.Button(frame, text="PINK", command=MODE49, bg=colorNormal, fg='pink', font=("Arial", 14, "bold"), bd=0)
MODE49.place(anchor='nw', x=100+172*9, y=475, width=172, height=100)



SPEEDLABEL = tk.Label(frame, text="MOOD", bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
SPEEDLABEL.place(anchor='nw', x=100+172*0, y=350, width=172, height=100)

def MODE21():  ## WHITE
    arduinoData.write('21'.encode())
    arduinoData.write('>'.encode())
def MODE22():  ## RED
    arduinoData.write('22'.encode())
    arduinoData.write('>'.encode())
def MODE23():  ## GREEN
    arduinoData.write('23'.encode())
    arduinoData.write('>'.encode())
def MODE24():
    arduinoData.write('24'.encode())
    arduinoData.write('>'.encode())
def MODE25():
    arduinoData.write('25'.encode())
    arduinoData.write('>'.encode())
def MODE26():
    arduinoData.write('26'.encode())
    arduinoData.write('>'.encode())
def MODE27():
    arduinoData.write('27'.encode())
    arduinoData.write('>'.encode())
def MODE28():
    arduinoData.write('28'.encode())
    arduinoData.write('>'.encode())
def MODE29():
    arduinoData.write('29'.encode())
    arduinoData.write('>'.encode())


MODE21 = tk.Button(frame, text="CLOUD", command=MODE21, bg=colorNormal, fg='cyan', font=("Arial", 14, "bold"), bd=0)
MODE21.place(anchor='nw', x=100+172*1, y=350, width=172, height=100)

MODE22 = tk.Button(frame, text="LAVA", command=MODE22, bg=colorNormal, fg='orange', font=("Arial", 14, "bold"), bd=0)
MODE22.place(anchor='nw', x=100+172*2, y=350, width=172, height=100)

MODE23 = tk.Button(frame, text="FORREST", command=MODE23, bg=colorNormal, fg='green', font=("Arial", 14, "bold"), bd=0)
MODE23.place(anchor='nw', x=100+172*3, y=350, width=172, height=100)

MODE24 = tk.Button(frame, text="OCEAN", command=MODE24, bg=colorNormal, fg='blue', font=("Arial", 14, "bold"), bd=0)
MODE24.place(anchor='nw', x=100+172*4, y=350, width=172, height=100)

MODE25 = tk.Button(frame, text="GREEN & PURPLE", command=MODE25, bg=colorNormal, fg='white', font=("Arial", 12, "bold"), bd=0)
MODE25.place(anchor='nw', x=100+172*5, y=350, width=172, height=100)

MODE26 = tk.Button(frame, text="ORANGE & BLUE", command=MODE26, bg=colorNormal, fg='white', font=("Arial", 12, "bold"), bd=0)
MODE26.place(anchor='nw', x=100+172*6, y=350, width=172, height=100)

MODE27 = tk.Button(frame, text="RED & BLUE", command=MODE27, bg=colorNormal, fg='white', font=("Arial", 12, "bold"), bd=0)
MODE27.place(anchor='nw', x=100+172*7, y=350, width=172, height=100)

MODE28 = tk.Button(frame, text="ORANGE & GREEN", command=MODE28, bg=colorNormal, fg='white', font=("Arial", 12, "bold"), bd=0)
MODE28.place(anchor='nw', x=100+172*8, y=350, width=172, height=100)

MODE29 = tk.Button(frame, text="YELLOW & RED", command=MODE29, bg=colorNormal, fg='white', font=("Arial", 12, "bold"), bd=0)
MODE29.place(anchor='nw', x=100+172*9, y=350, width=172, height=100)



SPEEDLABEL = tk.Label(frame, text="FULL COLOR", bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
SPEEDLABEL.place(anchor='nw', x=100+172*0, y=600, width=172, height=100)

def MODE11():  ## WHITE
    arduinoData.write('11'.encode())
    arduinoData.write('>'.encode())
def MODE12():  ## RED
    arduinoData.write('12'.encode())
    arduinoData.write('>'.encode())
def MODE13():  ## GREEN
    arduinoData.write('13'.encode())
    arduinoData.write('>'.encode())
def MODE14():
    arduinoData.write('14'.encode())
    arduinoData.write('>'.encode())
def MODE15():
    arduinoData.write('15'.encode())
    arduinoData.write('>'.encode())
def MODE16():
    arduinoData.write('16'.encode())
    arduinoData.write('>'.encode())
def MODE17():
    arduinoData.write('17'.encode())
    arduinoData.write('>'.encode())
def MODE18():
    arduinoData.write('18'.encode())
    arduinoData.write('>'.encode())
def MODE19():
    arduinoData.write('19'.encode())
    arduinoData.write('>'.encode())


MODE11 = tk.Button(frame, text="WHITE", command=MODE11, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
MODE11.place(anchor='nw', x=100+172*1, y=600, width=172, height=100)

MODE12 = tk.Button(frame, text="RED", command=MODE12, bg=colorNormal, fg='red', font=("Arial", 14, "bold"), bd=0)
MODE12.place(anchor='nw', x=100+172*2, y=600, width=172, height=100)

MODE13 = tk.Button(frame, text="ORANGE", command=MODE13, bg=colorNormal, fg='orange', font=("Arial", 14, "bold"), bd=0)
MODE13.place(anchor='nw', x=100+172*3, y=600, width=172, height=100)

MODE14 = tk.Button(frame, text="YELLOW", command=MODE14, bg=colorNormal, fg='yellow', font=("Arial", 14, "bold"), bd=0)
MODE14.place(anchor='nw', x=100+172*4, y=600, width=172, height=100)

MODE15 = tk.Button(frame, text="GREEN", command=MODE15, bg=colorNormal, fg='green', font=("Arial", 14, "bold"), bd=0)
MODE15.place(anchor='nw', x=100+172*5, y=600, width=172, height=100)

MODE16 = tk.Button(frame, text="CYAN", command=MODE16, bg=colorNormal, fg='cyan', font=("Arial", 14, "bold"), bd=0)
MODE16.place(anchor='nw', x=100+172*6, y=600, width=172, height=100)

MODE17 = tk.Button(frame, text="BLUE", command=MODE17, bg=colorNormal, fg='blue', font=("Arial", 14, "bold"), bd=0)
MODE17.place(anchor='nw', x=100+172*7, y=600, width=172, height=100)

MODE18 = tk.Button(frame, text="PURPLE", command=MODE18, bg=colorNormal, fg='purple', font=("Arial", 14, "bold"), bd=0)
MODE18.place(anchor='nw', x=100+172*8, y=600, width=172, height=100)

MODE19 = tk.Button(frame, text="PINK", command=MODE19, bg=colorNormal, fg='pink', font=("Arial", 14, "bold"), bd=0)
MODE19.place(anchor='nw', x=100+172*9, y=600, width=172, height=100)



def MODE1():
     arduinoData.write('1'.encode())
     arduinoData.write('>'.encode())

def MODE2():
    arduinoData.write('2'.encode())
    arduinoData.write('>'.encode())

def MODE3():
    arduinoData.write('3'.encode())
    arduinoData.write('>'.encode())

def MODE4():
    arduinoData.write('4'.encode())
    arduinoData.write('>'.encode())

def MODE5():
    arduinoData.write('5'.encode())
    arduinoData.write('>'.encode())

def MODE6():
    arduinoData.write('6'.encode())
    arduinoData.write('>'.encode())

def MODE7():
    arduinoData.write('7'.encode())
    arduinoData.write('>'.encode())

def MODE8():
    arduinoData.write('8'.encode())
    arduinoData.write('>'.encode())

def MODE9():
    arduinoData.write('9'.encode())
    arduinoData.write('>'.encode())

def MODE10():
    arduinoData.write('10'.encode())
    arduinoData.write('>'.encode())

def MODE31():
    arduinoData.write('11'.encode())
    arduinoData.write('>'.encode())

def MODE32():
    arduinoData.write('12'.encode())
    arduinoData.write('>'.encode())


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


#### SPEEEDDDD
SPEEDLABEL = tk.Label(frame, text="SPEED", bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
SPEEDLABEL.place(anchor='nw', x=100+172*0, y=880, width=172, height=100)

BPM1 = tk.Button(frame, text="15%", command=BPM1, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM1.place(anchor='nw', x=100+172*1, y=880, width=172, height=100)

BPM2 = tk.Button(frame, text="25%", command=BPM2, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM2.place(anchor='nw', x=100+172*2, y=880, width=172, height=100)

BPM3 = tk.Button(frame, text="35%", command=BPM3, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM3.place(anchor='nw', x=100+172*3, y=880, width=172, height=100)

BPM4 = tk.Button(frame, text="50%", command=BPM4, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM4.place(anchor='nw', x=100+172*4, y=880, width=172, height=100)

BPM5 = tk.Button(frame, text="60%", command=BPM5, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM5.place(anchor='nw', x=100+172*5, y=880, width=172, height=100)

BPM6 = tk.Button(frame, text="70%", command=BPM6, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM6.place(anchor='nw', x=100+172*6, y=880, width=172, height=100)

BPM7 = tk.Button(frame, text="80%", command=BPM7, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM7.place(anchor='nw', x=100+172*7, y=880, width=172, height=100)

BPM8 = tk.Button(frame, text="90%", command=BPM8, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM8.place(anchor='nw', x=100+172*8, y=880, width=172, height=100)

BPM9 = tk.Button(frame, text="100%", command=BPM9, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM9.place(anchor='nw', x=100+172*9, y=880, width=172, height=100)




def BRI1():
    arduinoData.write('81'.encode())
    arduinoData.write('>'.encode())

def BRI2():
    arduinoData.write('82'.encode())
    arduinoData.write('>'.encode())

def BRI3():
    arduinoData.write('83'.encode())
    arduinoData.write('>'.encode())

def BRI4():
    arduinoData.write('84'.encode())
    arduinoData.write('>'.encode())

def BRI5():
    arduinoData.write('85'.encode())
    arduinoData.write('>'.encode())

def BRI6():
    arduinoData.write('86'.encode())
    arduinoData.write('>'.encode())

def BRI7():
    arduinoData.write('87'.encode())
    arduinoData.write('>'.encode())

def BRI8():
    arduinoData.write('88'.encode())
    arduinoData.write('>'.encode())

def BRI9():
    arduinoData.write('89'.encode())
    arduinoData.write('>'.encode())

### BRIGHTNESSSSS
SPEEDLABEL = tk.Label(frame, text="BRIGHTNESS", bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
SPEEDLABEL.place(anchor='nw', x=100+172*0, y=780, width=172, height=100)

BPM1 = tk.Button(frame, text="15%", command=BRI1, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM1.place(anchor='nw', x=100+172*1, y=780, width=172, height=100)

BPM2 = tk.Button(frame, text="25%", command=BRI2, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM2.place(anchor='nw', x=100+172*2, y=780, width=172, height=100)

BPM3 = tk.Button(frame, text="35%", command=BRI3, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM3.place(anchor='nw', x=100+172*3, y=780, width=172, height=100)

BPM4 = tk.Button(frame, text="50%", command=BRI4, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM4.place(anchor='nw', x=100+172*4, y=780, width=172, height=100)

BPM5 = tk.Button(frame, text="60%", command=BRI5, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM5.place(anchor='nw', x=100+172*5, y=780, width=172, height=100)

BPM6 = tk.Button(frame, text="70%", command=BRI6, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM6.place(anchor='nw', x=100+172*6, y=780, width=172, height=100)

BPM7 = tk.Button(frame, text="80%", command=BRI7, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM7.place(anchor='nw', x=100+172*7, y=780, width=172, height=100)

BPM8 = tk.Button(frame, text="80%", command=BRI8, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM8.place(anchor='nw', x=100+172*8, y=780, width=172, height=100)

BPM9 = tk.Button(frame, text="100%", command=BRI9, bg=colorNormal, fg='white', font=("Arial", 14, "bold"), bd=0)
BPM9.place(anchor='nw', x=100+172*9, y=780, width=172, height=100)



root.bind('<Escape>', lambda e: root.destroy())

while True:
    root.update()
