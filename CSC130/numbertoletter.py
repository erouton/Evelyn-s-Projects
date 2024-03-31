'''
Converts numerical grades to letter grades
Input: Number, entered by the user
Output: letter grade corresponding to the numeric grade
'''
number_grade = input("Please enter a numeric grade: ")
print(number_grade)

number_grade = int(number_grade)

if number_grade >= 90:
    letter_grade = "A"
    
elif number_grade >= 80:
    letter_grade = "B"
    
elif number_grade >= 70:
    letter_grade = "C"
    
elif number_grade >= 60:
    letter_grade = "D"
    
elif number_grade < 60:
    letter_grade = "F"
    
print('If you get a', number_grade, 'then you will have a', letter_grade)
                    
