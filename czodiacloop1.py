'''
Returns Chinese zodiac symbol for a given year
'''
zodiac = ["Monkey", "Rooster", "Dog", "Pig", "Rat", "Ox",
          "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat"]

while True:
    year = input("Please enter a year in the western calendar. ")
    if year == "Quit":
        print("Thank you for using the Chinese zodiac program!")
        break
    elif not year.isdigit():
        print("Please enter a valid year.")
        continue
    year = int(year) #Convert year to an integer
    index = year % 12
    print(zodiac[index])
print("The loop is over")
   


