import copy
import keyboard

HEIGHT = 10
WIDTH = 30


def screen(liness):
    for i in range(HEIGHT):
        line = ""
        for ii in range(WIDTH):
            line += liness[i][ii]
        print(line)

def drawMap():
    lines = []
    for i in range(HEIGHT):
        lines.append([])
    
    for i in range(HEIGHT-2):
       for ii in range(WIDTH):
           lines[i+1].append(" ")
    
    for i in range(WIDTH):
        lines[0].append("-")
    for i in range(WIDTH):
        lines[HEIGHT-1].append("-")
    
    
                              
    return lines

x, y = 15, 5
lines = drawMap()
linesB = copy.deepcopy(lines)


while True:
    lines = copy.deepcopy(linesB)
    lines[y][x] = "*"
    screen(lines)
    
    
    if keyboard.is_pressed():
        i = keyboard.read_key()
        if i == "a" or i == "A":
            x -= 1
        elif i == "s" or i == "S":
            y += 1
        elif i == "d" or i == "D":
            x += 1
        elif i == "w" or i == "W":
            y -= 1
        elif i == "z" or i == "Z":
            linesB[y][x] = "o"
    