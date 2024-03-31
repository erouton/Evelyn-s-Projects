'''
Read a file and print the contents to the console
'''
def read1(fname):
    '''Opens fname for reading and prints using "for line in"'''
    f = open(fname, 'r')
    for line in f: #Gets one line at a time from f
        print(line, end = '')
    f.close() #Tell the operating system we're done with the file

def read2(fname):
    '''Opens fname for reading and reads all lines before printing'''
    f = open(fname, 'r')
    lines = f.readlines() #Read all lines into a list of strings
    f.close()
    return lines

def count_char(text, char):
    '''Returns the number of occurences of char in text'''
    count = 0 #Used to count the numer of occurences of char
    for line in text:
        for c in line.lower():
            if c == char:
                count += 1
    return count

def main():
    '''Controls the program'''
    filename = "PeterPiper.txt"
    text = read2(filename)
    char_count = count_char(text, 'p')
    print(f"There are {char_count} p's in the file")
    read1(filename)

main() #Starts execution
