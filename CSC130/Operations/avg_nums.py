'''
Averages a list of numbers
'''
def avg(nums):
    '''Returns the average of the numbers in list nums'''
    print("Nums:", nums)
    total = 0
    for n in nums:
        total = total + n #Can also use total += n
        print("Total:", total)
    average = total/len(nums)
    return round(average, 2)

def main():
    my_list = [12, 15, 25, 42, 9]
    av = avg(my_list)
    print("The average is", av)

main() #start execution
