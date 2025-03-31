import random

import signal

import sys

def timeout_handler(signum, frame):

    print("\n The execution time is over. The lottery has been terminated!")

    sys.exit(1)
    
signal.signal(signal.SIGXCPU, timeout_handler)

def generate_lottery():

    numbers_49 = random.sample(range(1, 50), 7)
    
    numbers_36 = random.sample(range(1, 37), 6)
    
    return numbers_49, numbers_36
    
filename = "lottery_results.txt"

try:

    with open(filename, "w") as f:
    
        for _ in range(1000000):  
        
            n49, n36 = generate_lottery()
            
            f.write(f"7 із 49: {n49} | 6 із 36: {n36}\n")
            
except Exception as e:

    print(f" Error: {e}")
    
print(f" The lottery is over. Results in {filename}")
