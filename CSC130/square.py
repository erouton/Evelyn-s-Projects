'''
Draw a square using a turtle
'''
import turtle

space = turtle.Screen()


def draw_square(t, length, x, y, color):
    t.color(color)
    t.penup()
    t.goto(x, y) #Position turtle t before drawing the square
    t.pendown()
    for i in range(4):
        t.forward(length)
        t.left(90)

def main():
    alex = turtle.Turtle()
    draw_square(alex, 50, 25, 50, 'red')
    draw_square(alex, 25, -100, -75, 'blue')
    
main()  #Start Execution
