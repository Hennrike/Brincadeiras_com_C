import pygame
from sys import exit

icon = pygame.image.load("DoomGame/gameIcon.png")

pygame.init()
screen = pygame.display.set_mode((800, 400))
pygame.display.set_caption("Runner")
pygame.display.set_icon(icon)
clock = pygame.time.Clock()

test_surface = 

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()

    screen.blit(test_surface, (200, 100))

    pygame.display.update()
    clock.tick(60)