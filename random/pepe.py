import pygame
import math
import time

pygame.init()
window = pygame.display.set_mode((800, 600))

RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

p1x, p1y, p1color, score1 = 0, 300, RED, 0
p2x, p2y, p2color, score2 = 780, 300, GREEN, 0
bx, by, bcolor, bdirx, bdiry = 400, 300, WHITE, 1, 1
pSpeed = 2
bspeed = 1.0
sleeping = 1


def draw_cube(posx, posy, color, sizex, sizey):
    for X in range(sizex):
        for Y in range(sizey):
            window.set_at((posx + X, posy + Y), (color))
            
def draw_circle(center_x, center_y, radius):
    for y in range(-radius, radius + 1):
        for x in range(-radius, radius + 1):
            if x**2 + y**2 <= radius**2:
                window.set_at((center_x + x, center_y + y), BLACK)

game = 1
while game == 1:
    
    
    bx += round(bdirx * bspeed)
    by += round(bdiry * bspeed)
    
    
    
    
    if by > 575:
        bdiry = -1
    if by < 25:
        bdiry = 1
    if bx > 760 and (by >= p2y and by <= p2y + 100):
        bspeed += 0.1
        bdirx = -1
    if bx < 40 and (by >= p1y and by <= p1y + 100):
        bspeed += 0.1
        bdirx = 1
    
    if bx < 0:
        score1 += 1
        bx, by = 400, 300
        p1y, p2y = 300, 300
        sleeping = 1
    if bx > 800:
        score2 += 1
        bx, by = 400, 300
        sleeping = 1
    
    key = pygame.key.get_pressed()
    if key:
        if key[pygame.K_s]:
            if p1y < 500:
                p1y += pSpeed
        if key[pygame.K_w]:
            if p1y > 0:
                p1y -= pSpeed
        
        if key[pygame.K_DOWN]:
            if p2y < 500:
                p2y += pSpeed
        if key[pygame.K_UP]:
            if p2y > 0:
                p2y -= pSpeed
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game = 0
            
    
    print(score1, score2)
    
    window.fill(WHITE)
    if score1 > 3:
        draw_cube(10, 10, BLACK, 30, 30)
        draw_cube(50, 10, BLACK, 30, 30)
        draw_cube(90, 10, BLACK, 30, 30)
    
    draw_cube(p1x, p1y, p1color, 20, 100)
    draw_cube(p2x, p2y, p2color, 20, 100)
    draw_circle(bx, by, 25)
    
    pygame.display.update()
    
    if sleeping == 1:
        time.sleep(1)
        bspeed = 1.0
        sleeping = 0