'''
Race 3 turtles
'''
import turtle
import random

FINISH_X = 200
FINISH_Y = 250
FINISH_LENGTH = 500

window = turtle.Screen()

def finish_line(t, x, y, length):
    start_dir = int(t.heading())
    startx = int(t.xcor())
    starty = int(t.ycor())
    '''Draws a veritcal line of length length at position x, y'''
    #t.color('red')
    t.pensize(3)
    t.penup()
    t.goto(x, y)
    t.pendown()
    t.setheading(270)
    t.forward(length)
    t.penup()
    t.goto(startx, starty)
    t.pendown()
    t.setheading(start_dir)

def main():
    #Create 3 turtles
    boo = turtle.Turtle()
    bee = turtle.Turtle()
    bill = turtle.Turtle()
    finish_line(boo, FINISH_X, FINISH_Y, FINISH_LENGTH)  #Draw the finish line
    boo.color('purple')#Set the turtles colors
    bee.color('orange')
    bill.color('blue')
    #Position the turtles at the start line
    boo.penup()
    bee.penup()
    bill.penup()
    boo.goto(-100, 20)
    bee.goto(-100, 0)
    bill.goto(-100, -20)
    #Set the pensizes
    boo.pensize(5)
    bee.pensize(5)
    bill.pensize(5)
    #Loop until finished
    while (int(boo.xcor()) < FINISH_X and int(bee.xcor()) < FINISH_X and
           int(bill.xcor()) < FINISH_X):
        #Move each turtle random distance
        boo.forward(random.randint(20, 50))
        bee.forward(random.randint(20, 50))
        bill.forward(random.randint(20, 50))
    #Declare a winner
    if int(boo.xcor()) > int(bee.xcor()) and int(boo.xcor()) > int(bill.xcor()):
        print('Boo wins!!!')
    elif int(bee.xcor()) > int(boo.xcor()) and int(bee.xcor()) > int(bill.xcor()):
        print('Bee wins!!!')
    elif int(bill.xcor()) > int(boo.xcor()) and int(bill.xcor()) > int(bee.xcor()):
        print('Bill wins!!!')
    else:
        print('We have a tie!')

main()


