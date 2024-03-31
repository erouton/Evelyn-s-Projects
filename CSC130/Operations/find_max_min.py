'''
Averages a list of numbers
'''
import math

def find_max(nums):
    maximum = -math.inf
    for n in nums:
        if n > maximum:
            maximum = n
            print("Current max:", maximum)
    return maximum

def find_min(nums):
    print("Nums:", nums)
    minimum = math.inf
    for n in nums:
        if n < minimum:
            minimum = n
            print("Current min:", minimum)
    return minimum

def main():
    my_list = [12, 15, 7, 25, 42, 9]
    min_val = find_min(my_list)
    print("The maximum is", min_val)

main() #start execution
