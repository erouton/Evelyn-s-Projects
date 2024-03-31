'''
Show effect of scope in functions
'''
def avg(a, b):
    total = a + b
    av = total/2
    a = a + 10
    b = b + 10
    return av

def main():
    x = 10
    y = 5
    print(avg(x, y))
    print(x, y)

main()
