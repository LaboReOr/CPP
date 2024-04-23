import time
import random


abc = ["a", "b", "c", "d", "e", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
    
while True:
    alumnos = []
    alumno = ""
    for i in range(random.randint(3, 8)):
        alumno += abc[random.randint(0, len(abc)-1)]


    abc = " AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789#$%&/()=?¡'¿+-_.:,;<>!"
    pal = alumno
    palx = ""
    print(pal)
    for ch in range(len(pal)):
        for i in range(len(abc)):
            
            time.sleep(0.025)
            print(palx + abc[i])
            
            if abc[i] == pal[ch]: 
                palx = palx + abc[i]
                break
    if pal == "camilo":
        break 