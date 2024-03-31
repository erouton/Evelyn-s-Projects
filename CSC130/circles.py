'''
Draw circleson a background image
'''
import turtle
window = turtle.Screen()

def draw_circle(t, x, y, r):
    '''Draws a circle of radius r at position x, y'''
    t.penup()
    t.goto(x, y)
    t.pendown()
    t.begin_fill()
    t.circle(r)
    t.end_fill()

def main():
    window.bgpic('pumpkin1.gif')
    boo = turtle.Turtle()
    boo.color('red')
    boo.fillcolor('pink')
    boo.pensize(6)
    draw_circle(boo, -190, 150, 20)
    draw_circle(boo, 125, 175, 20)

main()
