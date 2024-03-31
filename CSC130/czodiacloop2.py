'''
Returns Chinese zodiac symbol for a given year
'''
zodiac = ["Monkey", "Rooster", "Dog", "Pig", "Rat", "Ox",
          "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat"]

num_years = input("How many years do you want to enter?")
num_years = int(num_years) #convert to int
for loop_variable in range(num_years): #range gives a list of ints (0 to num_years)
    #print("loop_variable:", loop_variable)
    year = input("Please enter a year in the western calendar.")
    year = int(year) #Convert year to an integer
    index = year % 12
    print(zodiac[index])
print("The loop is over")
   


