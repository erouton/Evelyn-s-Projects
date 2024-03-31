'''
Draw a line of square
'''
import turtle

window = turtle.Screen() #Create a window for drawing

DISTANCE = 50 #Distance between squares
SIZE = 50 #Size of squares

def draw_square(t, size, x, y):
    '''Draw a square using turtle t with lower left corner at x, y'''
    t.penup() #Pick up the pen
    t.goto(x, y) #Move turtle to position x, y
    t.pendown() #Put the pen down
    t.pensize(5) #Make the turtle draw a thicker line
    #Draw a square with sides of length size
    for color in ["blue", "red", "pink", "purple"]:
        t.color(color)
        t.forward(size)
        t.left(90)

def main():
    evie = turtle.Turtle() #Create a turtle
    x = -250
    for _ in range(5):
        draw_square(evie, SIZE, x, 0) #Draw square 1 
        x += SIZE + DISTANCE      

main() #Start execution
