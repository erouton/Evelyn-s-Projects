'''
Manage names and phone numbers
'''
pb = {"Braeg" : "111-1111", "Hailey" : "222-2222", "CousHailey" : "333-3333",
      "Marcus" : "444-4444", "Brian" : "555-5555"}

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
