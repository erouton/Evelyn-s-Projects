'''
Print the lyrics to 99 bottles of beer on the wall
'''
for num in range(99, 0, -1): #Start at 99, go to 0, step -1
    if num == 1: #Print correct grammar for 1 bottle
        print(num, "bottle of beer on the wall")
        print(num, "bottle of beer")
    else: #Print correct grammar for multiple bottles
        print(num, "bottles of beer on the wall")
        print(num, "bottles of beer")
    print("Take one down, pass it around")
    if num ==2:
        print(num - 1, "bottle of beer on the wall")
    else:
        print(num - 1, "bottles of beer on the wall")
    print() #Print a blank line to seperate verses
    
