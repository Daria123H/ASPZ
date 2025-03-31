import sys

sys.setrecursionlimit(2000) 

print(f"Current recursion limit: {sys.getrecursionlimit()}")

def recursive_function(depth=0):

    print(f"Recursion depth: {depth}")
    
    recursive_function(depth + 1)
    
recursive_function() 
