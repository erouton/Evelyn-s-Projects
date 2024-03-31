'''
Asn2: Functions
Author: Evelyn Routon
'''
import turtle
window = turtle.Screen()  #Used in Asn2_4

def asn2_1(num1, num2, num3):
    #Prints the sum of 3 nums
    sum = num1 + num2 + num3
    print(sum)

def asn2_2(num1, num2, num3, num4, num5):
    #Returns the amount of odd nums
    odds = 0
    for num in (num1, num2, num3, num4, num5):
        if num % 2 == 0:
            odds+= 0
        elif num % 2 == 1:
            odds+= 1
    return odds
        

def asn2_3(d):
    '''Returns the area of a pizza. d is the pizza's diameter.'''
    ra = d/2
    area = 3.14159 * ra**2
    return area

def draw_circle(t, x, y, radius):
    '''Draws a circle with radius r at position x, y'''
    t.penup()  #Enter code to draw a circle; don't draw lines connecting them
    t.goto(x, y)
    t.pendown()
    t.circle(radius)

def asn2_4():
    boo = turtle.Turtle() #Create a turtle
    rad = 20
    boo.pensize(3) #set pensize to 3
    #create a red circle at x,y
    boo.color('red')
    draw_circle(boo, -200, 200, rad)
    #create a green circle at x,y
    boo.color('green')
    draw_circle(boo, 200, 200, rad)
    #create a blue circle at x,y
    boo.color('blue')
    draw_circle(boo, -200, -200, rad)
    #create an orange circle at x,y
    boo.color('orange')
    draw_circle(boo, 200, -200, rad)
    #create a purple circle at x,y
    boo.color('purple')
    draw_circle(boo, 0, 0, rad)

def main():
    '''Change only the statements you are directed to change below'''
    asn2_1(10, 12, 14)  #Do not change this statement
    num_odds = asn2_2(10, 11, 15, 18, 21)  #Do not change this statement
    print("There are", num_odds, "odd numbers")  #Do not change this statement
    for diameter in [10, 12, 16]:
        print("The area of a", diameter, "inch pizza equals",asn2_3(diameter))
    asn2_4()  #Do not change this statement
    window.exitonclick()      #Do not change this statement

main()
    
   
