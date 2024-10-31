"""
Evelyn Routon
Operating Systems
Programming Project #5: Simulation of Page Replacement Strategies
October 30, 2024
Instructor: Dr. Siming Liu
"""
import sys
import random

# Page replacement algorithms

def fifo(page_references, frames):
    frame = []
    page_faults = 0
    for page in page_references:
        if page not in frame:
            page_faults += 1
            if len(frame) >= frames:
                frame.pop(0)
            frame.append(page)
    return page_faults

def lru(page_references, frames):
    frame = []
    page_faults = 0
    for page in page_references:
        if page in frame:
            frame.remove(page)
        else:
            page_faults += 1
            if len(frame) >= frames:
                frame.pop(0)
        frame.append(page)
    return page_faults

def opt(page_references, frames):
    frame = []
    page_faults = 0
    for i, page in enumerate(page_references):
        if page not in frame:
            page_faults += 1
            if len(frame) < frames:
                frame.append(page)
            else:
                future_uses = [page_references[i+1:].index(p) if p in page_references[i+1:] else float('inf') for p in frame]
                frame.pop(future_uses.index(max(future_uses)))
                frame.append(page)
    return page_faults

def rand(page_references, frames):
    frame = []
    page_faults = 0
    for page in page_references:
        if page not in frame:
            page_faults += 1
            if len(frame) >= frames:
                frame[random.randint(0, frames-1)] = page
            else:
                frame.append(page)
    return page_faults

# Main function

def main():
    # Input handling
    input_lines = sys.stdin.read().splitlines()
    page_references = list(map(int, input_lines[0].split()))
    frames = int(input_lines[1])
    algorithms = input_lines[2:]
    
    # Output
    print("Page Reference String:")
    print(" ".join(map(str, page_references)))
    print(f"Number of Frames: {frames}")
    
    # Execute each algorithm and output page faults
    for algo in algorithms:
        if algo == "FIFO":
            faults = fifo(page_references, frames)
        elif algo == "LRU":
            faults = lru(page_references, frames)
        elif algo == "OPT":
            faults = opt(page_references, frames)
        elif algo == "RAND":
            faults = rand(page_references, frames)
        print(f"{algo}: {faults}")

if __name__ == "__main__":
    main()
