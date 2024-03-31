'''
Manage names and phone numbers
'''
pb = {"Lily" : "111-1111", "Corey" : "222-2222", "Sally" : "333-3333",
      "Sasha" : "444-4444", "Hank" : "555-5555"}

def print_book(pb):
    key_list = list(pb.keys())
    key_list.sort()
    for key in key_list:
        print(key, pb[key])

def main():
    name = input("Please enter a name ")
    num = pb[name]
    print("The number is", num)
    print("Hi", name, "would you like to go to the party with me?")

print_book(pb)
