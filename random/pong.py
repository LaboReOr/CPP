import msvcrt
from msvcrt import getch
from msvcrt import kbhit
import os
import random
from random import randint

mapa = [[0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 1, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0]]
mapaLiso = [0, 0, 0, 0, 0, 0, 0, 0, 0]
mapLi2 = "_" # Relleno de los cuadrados libres del mapa

controller = ["w", "a", "s", "d"]

bucle = True
keyPress = 0
####################################################################################################
# FUNCIONES #
####################################################################################################
def clear():
    for i in range(30):
        print(" ")


def mapeado(mapita, mapLi):
    mapeje = [[mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi],[mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi],[mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi],[mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi],[mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi],[mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi],[mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi],[mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi],[mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi, mapLi]]
    mapView = []
    rango = 9
    rangoC = 9
    
    # PosY_Y = 0
    # PosX_Y = 0
       
    # PosY_C = 0
    # PosX_C = 0 
    
    mapView.clear()
    mapView = mapeje
    for Y in range(rango): # Y es el personajes
        if(mapita[Y].count(1) == 1):
            rango = 0
            mapView[Y].insert(mapita[Y].index(1), "Y")
            mapView[Y].pop(-1)
            rango = 0
    #         PosY_Y = Y
    #         PosX_Y = mapita[Y].index(1)
    # for C in range(rangoC): # C es la moneda
    #     if(mapita[C].count(1) == 2):
    #         PosX_C = mapita[C].count(1)
    #         PosY_C = C
    #         if(PosX_Y != PosX_C or PosY_Y != PosY_C):
    #             rango = 0
    #             mapView[C].insert(mapita[C].index(2), "O")
    #             mapView[C].pop(-1)
    #             rango = 0
    #mapView = "".join(mapView)
    return(mapView)

def movYX(mpa, mLiso, kPress):
    rango = 9
    for i in range(rango):
        if(mpa[i].count(1) == 1):
            posY = i
            posX = mpa[i].index(1)
            rango = 0
    if(kPress == "w"):
        if(posY > 0):
            mpa[posY].insert(posX, 0)
            mpa[posY].pop(posX+1)
            mpa[posY-1].insert(posX, 1)
            mpa[posY-1].pop(posX+1)
    elif(kPress == "s"):
        if(posY < 8):
            mpa[posY].insert(posX, 0)
            mpa[posY].pop(posX+1)
            mpa[posY+1].insert(posX, 1)
            mpa[posY+1].pop(posX+1)
    elif kPress == "a":
        if(posX > 0):
            mpa[posY][posX-1], mpa[posY][posX] = 1, 0 # Cuando ponemos una variable, otra variable = valor, valor. Le asignamos a la primera variable el primer valor y a la segunda la segunada
            posX -= 1
    elif kPress == "d":
        if(posX < 8):
            mpa[posY][posX+1], mpa[posY][posX] = 1, 0
            posX += 1
    return mpa, posY, posX

# def coin(mpa):
#     posX = randint(0,8)
#     posY = randint(0,8)
#     mpa[posY][posX] = 2
    

    
####################################################################################################
# CODIGO #
####################################################################################################

#MAPEADO
#clear()
os.system('cls' if os.name == 'nt' else 'clear') # Limpiar consola
print(f"Y: 0, X: 0") 
mapita = mapeado(mapa, mapLi2)
print("_".join([mapLi2, mapLi2, mapLi2, mapLi2, mapLi2, mapLi2, mapLi2, mapLi2, mapLi2, mapLi2]))
for i in range(9):
    print("|" + "|".join(mapita[i]) + "|")


while(bucle):
    if(kbhit() == True): # Verificar si una tecla se presiona
        keyPress = getch().decode() # Ver que tecla se presiono
        if(keyPress == "0"):
            bucle = False
        elif(keyPress in controller):
            movYX2 = movYX(mapa, mapaLiso, keyPress)
            mapa = movYX2[0]
            # if(randint(0,1) == 1):
            #     mapa = coin(mapa)
            #MAPEADO
            #clear()
            os.system('cls' if os.name == 'nt' else 'clear') # Limpiar consola
            print(f"Y: {movYX2[1]}, X: {movYX2[2]}") 
            mapita = mapeado(mapa, mapLi2)
            print("_".join([mapLi2, mapLi2, mapLi2, mapLi2, mapLi2, mapLi2, mapLi2, mapLi2, mapLi2, mapLi2]))
            for i in range(9):
                print("|" + "|".join(mapita[i]) + "|")