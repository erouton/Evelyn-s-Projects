'''
Draw a set of nested squares using a turtle
'''
import turtle
import random

window = turtle.Screen()

def draw_square(t, size):
    '''Draw a square using turtle t at the current position'''
    for i in range(4):
        t.forward(size)
        t.left(90)
        
def centered_square(t, x, y, size):
    '''Draws a square centered on the x, y position'''
    t.penup() #Lift the pen so a line is not drawn
    t.goto(x - size/2, y - size/2) #Position turtle relative to center of square
    t.pendown() #Pen down for drawing
    draw_square(t, size)
   
def main():
    '''Controls the program'''
    colors = ['pink', 'cyan', 'purple', 'light blue']
    boo = turtle.Turtle() #Create a turtle named boo
    boo.pensize(5)
    for length in range(20, 220, 20):
        c = random.choice(colors)
        boo.color(c)
        centered_square(boo, 0, 0, length)

main() #Start execution
