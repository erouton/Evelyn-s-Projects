'''
Count words in a text file
'''
import string

def readfile(fname):
    '''Returns the contents of fname as one lower case string'''
    f = open(fname, 'r')  #Open file for reading
    contents = f.read()   #Read entire file into contents
    f.close()  #Tell the operating system that we're done with the file
    for char in string.punctuation:
        contents = contents.replace(char, '')  #Replace punctuation chars with null string
    return contents.lower()

def build_dict(s, stopwords):
    '''Builds a dictionary of words and their counts from string s'''
    d = {}  #Start with an empty dictionary
    words = s.split()  #Split s on whitespace into a list of words
    print("There are", len(words), "in Shakespear's sonnets") 
    stop_list = stopwords.split()
    for w in words:
        if w not in stop_list:
            if w not in d:
                d[w] = 1
            else:
                d[w] = d[w] + 1  #same d[w] += 1
    print("There are", len(d), "unique words in Shakespear's sonnets")
    return d

def show_counts(d):
    '''Prints keys and counts to the screen'''
    for key in d:
        if d[key] >= 25:    #Only print words with counts higher than this
            print(key, d[key])

def main():
    filename = "Sonnets.txt"
    text = readfile(filename)
    stops = readfile("stopwords.txt")
    word_counts = build_dict(text, stops)  #Get a dictionary of word counts
    show_counts(word_counts)

main()
