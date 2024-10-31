"""
Evelyn Routon
Operating Systems
Project #4: Implementation of Banker's Algorithm
October 21, 2024
Instructor: Dr. Siming Liu
---------------------------------------------------
The purpose of this programming project is to explore resource allocation algorithms.  
This can be achieved by implementing the banker's algorithm as described in our textbook and discussed in class.

Example Input:
5

4

0 0 1 2
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4

0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6

1 5 2 0

1:0 4 2 0


Example Output:
There are 5 processes in the system.

There are 4 resource types.

The Allocation Matrix is...
   A B C D
0: 0 0 1 2
1: 1 0 0 0
2: 1 3 5 4
3: 0 6 3 2
4: 0 0 1 4

The Max Matrix is...
   A B C D
0: 0 0 1 2
1: 1 7 5 0
2: 2 3 5 6
3: 0 6 5 2
4: 0 6 5 6

The Need Matrix is...
   A B C D
0: 0 0 0 0
1: 0 7 5 0
2: 1 0 0 2
3: 0 0 2 0
4: 0 6 4 2

The Available Vector is...
A B C D
1 5 2 0

THE SYSTEM IS IN A SAFE STATE!

The Request Vector is...
  A B C D
1:0 4 2 0

THE REQUEST CAN BE GRANTED!

The Available Vector is...
A B C D
1 1 0 0

Reference
[1] GeeksforGeeks, "Banker's Algorithm | Set 1 (Safety Algorithm)," GeeksforGeeks, 2021. [Online]. Available: https://www.geeksforgeeks.org/program-bankers-algorithm-set-1-safety-algorithm/. [Accessed: 21-Oct-2024].
[2] Python Software Foundation, "Input and Output," Python 3 Documentation. [Online]. Available: https://docs.python.org/3/tutorial/inputoutput.html. [Accessed: 21-Oct-2024].

"""

# Function to calculate the Need matrix
def calculateNeedMatrix(need, maxm, allot, n, m):
    for i in range(n):
        for j in range(m):
            need[i][j] = maxm[i][j] - allot[i][j]


# Function to check if the system is in a safe state
def isSafeState(n, m, avail, maxm, allot, processes):
    need = [[0] * m for _ in range(n)]
    calculateNeedMatrix(need, maxm, allot, n, m)

    finish = [False] * n
    safeSeq = [0] * n
    work = avail[:]

    count = 0
    while count < n:
        found = False
        for p in range(n):
            if not finish[p]:
                if all(need[p][j] <= work[j] for j in range(m)):
                    for j in range(m):
                        work[j] += allot[p][j]
                    safeSeq[count] = p
                    count += 1
                    finish[p] = True
                    found = True
        if not found:
            print("THE SYSTEM IS NOT IN A SAFE STATE!\n")
            return False
    print("THE SYSTEM IS IN A SAFE STATE!\n")
    return True

# Function to handle request vector and check if it can be granted
def isRequestGrantable(request, p, avail, need, allot, n, m):
    if all(request[j] <= need[p][j] for j in range(m)) and all(request[j] <= avail[j] for j in range(m)):
        for j in range(m):
            avail[j] -= request[j]
            allot[p][j] += request[j]
            need[p][j] -= request[j]
        print("THE REQUEST CAN BE GRANTED!\n")
        return True
    print("THE REQUEST CANNOT BE GRANTED!\n")
    return False

def read_input_from_file():
    filename = 'input.txt'  # Assuming the input file is 'input.txt'
    with open(filename, 'r') as file:
        # Read lines and strip whitespace
        lines = [line.strip() for line in file.readlines() if line.strip()]
        
        n = int(lines[0])  # number of processes
        m = int(lines[1])  # number of resources
        allocation = [list(map(int, lines[i + 2].split())) for i in range(n)]
        maxm = [list(map(int, lines[i + 2 + n].split())) for i in range(n)]
        avail = list(map(int, lines[2 + 2*n].split()))
        request_line = lines[3 + 2*n].strip().split(":")
        request_process = int(request_line[0])
        request = list(map(int, request_line[1].split()))
    return n, m, allocation, maxm, avail, request_process, request

def print_matrix(matrix_name, matrix, n, m):
    print(f"The {matrix_name} Matrix is...")
    print("   " + " ".join(chr(65 + i) for i in range(m)))
    for i in range(n):
        print(f"{i}: " + " ".join(map(str, matrix[i])))
    print("\n")

def main():
    # Read input directly from bankerinput.txt
    n, m, allot, maxm, avail, request_process, request = read_input_from_file()

    # Echo number of processes and resource types
    print(f"There are {n} processes in the system.\n\n")
    print(f"There are {m} resource types.\n\n")

    # Echo allocation and max matrices
    print_matrix("Allocation", allot, n, m)
    print_matrix("Max", maxm, n, m)

    # Compute and print Need matrix
    need = [[0] * m for _ in range(n)]
    calculateNeedMatrix(need, maxm, allot, n, m)
    print_matrix("Need", need, n, m)

    # Echo available vector
    print("The Available Vector is...")
    print(" ".join(chr(65 + i) for i in range(m)))
    print(" ".join(map(str, avail)) + "\n")

    # Check if the system is in a safe state
    isSafeState(n, m, avail, maxm, allot, list(range(n)))

    # Echo request vector
    print(f"The Request Vector is...\n{request_process}:" + " ".join(map(str, request)) + "\n")

    # Check if the request can be granted
    if isRequestGrantable(request, request_process, avail, need, allot, n, m):
        print("The Available Vector is...")
        print(" ".join(chr(65 + i) for i in range(m)))
        print(" ".join(map(str, avail)) + "\n")

if __name__ == "__main__":
    main()

