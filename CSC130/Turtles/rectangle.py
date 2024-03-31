'''
Draw a rectangle using a turtle
'''
import turtle

space = turtle.Screen()
alex = turtle.Turtle()

def draw_rect(length1, length2):
    for i in [1,2]:
        alex.forward(length1)
        alex.left(90)
        alex.forward(length2)
        alex.left(90)

def main():
    draw_rect(100, 50)
    alex.penup()
    alex.back(250)
    alex.pendown()
    draw_rect(150, 75)
    
main()  #Start Execution
