'''
Illustration of a counting loop
'''
def count_items(list_of_items):
    '''Returns the number of items in the list'''
    count = 0
    for item in list_of_items:
        count = count + 1
    return count

my_list = [42, 12, "Hello", "Goodbye", 3.14159]
num_items = count_items(my_list)
print("There are", num_items, "items in the list")
print("Also, the length of the list is,", len(my_list))

