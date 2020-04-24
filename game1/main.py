import random
import pygame
import sys

from pygame.locals import *
# set up
snake_speed = 15
windows_height = 600
windows_width = 800
cell_size = 20

map_height = windows_height // cell_size
map_width = windows_width // cell_size

white = (255, 255, 255)
black = (0, 0, 0)
gray = (230, 230, 230)
dark_gray = (40, 40, 40)
dark_green = (0, 155, 0)
green = (0, 255, 0)
red = (255, 0, 0)
blue = (0, 0, 255)
dark_blue = (0, 0, 139)

bg_color = black

up = 1
down = 2
left = 3
right = 4

head = 0

# main


def main():
    pygame.init()
    snake_clock = pygame.time.Clock()
    screen = pygame.display.set_mode((windows_width, windows_height))
    screen.fill(white)

    pygame.display.set_caption("贪吃蛇")
    show_start_info(screen)
    while True:
        run(screen, snake_clock)
        show_gameover_info(screen)

# welcome


def show_start_info(screen):
    #font = pygame.font.Font('myfont.ttf', 40)
    #tip = font.render("按q/esc退出，其他任意键开始", True, (65, 105, 225))
    #screen.blit(tip, (80, 300))
    pygame.display.update()

    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                terminate()
            elif event.type == KEYDOWN:
                if event.key == K_ESCAPE or event.key == K_q:
                    terminate()
                else:
                    return

# run


def run(screen, snake_clock):
    startx = random.randint(3, map_width-8)
    starty = random.randint(3, map_height-8)
    snake_coords = [{'x': startx, 'y': starty}, {
        'x': startx-1, 'y': starty}, {'x': startx-2, 'y': starty}]
    direction = right
    food = get_random_location()
    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                terminate()
            elif event.type == KEYDOWN:
                if (event.key == K_LEFT or event.key == K_a)and direction!=right:
                    direction = left
                elif (event.key == K_RIGHT or event.key == K_d)and direction!=left:
                    direction = right
                elif (event.key == K_UP or event.key == K_w)and direction!=down:
                    direction = up
                elif (event.key == K_DOWN or event.key == K_s)and direction!=up:
                    direction = down
                elif event.key == K_ESCAPE:
                    terminate()
        move_snake(direction, snake_coords)
        if snake_die(snake_coords):
            break
        snake_eat(snake_coords, food)

        screen.fill(bg_color)
        draw_grid(screen)
        draw_snake(screen, snake_coords)
        draw_food(screen, food)
#        draw_score(screen, , len(snake_coords)-3)
        pygame.display.update()
        snake_clock.tick(snake_speed)

# draw food


def draw_food(screen, food):
    x = food['x']*cell_size
    y = food['y']*cell_size
    applerect = pygame.Rect(x, y, cell_size, cell_size)
    pygame.draw.rect(screen, red, applerect)

# draw snake


def draw_snake(screen, snake_coords):
    for coords in snake_coords:
        x = coords['x']*cell_size
        y = coords['y']*cell_size
        wormSegmentRect = pygame.Rect(x, y, cell_size, cell_size)
        pygame.draw.rect(screen, dark_blue, wormSegmentRect)
        wormInnerSegmentRect = pygame.Rect(x+4, y+4, cell_size-8, cell_size-8)
        pygame.draw.rect(screen, blue, wormInnerSegmentRect)

# draw grid


def draw_grid(screen):
    for x in range(0, windows_width, cell_size):
        pygame.draw.line(screen, dark_gray, (x, 0), (x, windows_height))
    for y in range(0, windows_height, cell_size):
        pygame.draw.line(screen, dark_gray, (0, y), (windows_width, y))

# move_snake


def move_snake(direction, snake_coords):
    if direction == up:
        newhead = {'x': snake_coords[head]['x'],
                   'y': snake_coords[head]['y']-1}
    if direction == down:
        newhead = {'x': snake_coords[head]['x'],
                   'y': snake_coords[head]['y']+1}
    if direction == left:
        newhead = {'x': snake_coords[head]['x'] -
                   1, 'y': snake_coords[head]['y']}
    if direction == right:
        newhead = {'x': snake_coords[head]['x'] +
                   1, 'y': snake_coords[head]['y']}
    snake_coords.insert(0, newhead)

# snake die


def snake_die(snake_coords):
    flag = True
    if (snake_coords[head]['x'] == -1 or snake_coords[head]['x'] == map_width)\
            or snake_coords[head]['y'] == -1 or snake_coords[head]['y'] == map_height:
        flag = False
    for snake_body in snake_coords[1:]:
        if snake_body['x'] == snake_coords[head]['x'] and snake_body['y'] == snake_coords[head]['y']:
            flag = False
    return not flag

# snake eat


def snake_eat(snake_coords, food):
    if snake_coords[head]['x'] == food['x'] and snake_coords[head]['y'] == food['y']:
        food['x'] = random.randint(0, map_width-1)
        food['y'] = random.randint(0, map_height-1)
    else:
        del snake_coords[-1]

# get random location


def get_random_location():
    return {'x': random.randint(0, map_width-1), 'y': random.randint(0, map_height-1)}

# show_gameover_info


def show_gameover_info(screen):
    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                terminate()
            elif event.type == KEYDOWN:
                if event.key == K_ESCAPE or event.key == K_q:
                    terminate()
                else:
                    return


def terminate():
    pygame.quit()
    sys.exit()


main()
