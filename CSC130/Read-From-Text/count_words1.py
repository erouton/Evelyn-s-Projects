'''
Count words in a text string
'''
s = '''Peter Piper picked a peck of pickled peppers
A peck of pickled peppers Peter Piper picked.
If Peter Piper picked a peck of pickled peppers
Where's the peck of pickled peppers Peter Piper picked?'''

def count_chars(txt):
    '''Returns a dictionary with characters and their counts'''
    char_dict = {} #Start with an empty dictionary
    for char in txt.lower():
        if char in char_dict: #If char is in the dictionary...
            char_dict[char] = char_dict[char] + 1 #...add 1 to the count
        else:                   #If char is not in the dictionary...
            char_dict[char] = 1 #...add it with a count of 1
    return char_dict

def show_counts(d):
    '''Display the keys and counts for dictionary d'''
    key_list = list(d.keys())
    key_list.sort()
    for key in key_list:
        if key == ' ':
            print("sp", d[key])
        elif key == '\n':
            print('nl', d[key])
        else:
            print(key, d[key])

def main():
    char_counts = count_chars(s)
    show_counts(char_counts)

main()
