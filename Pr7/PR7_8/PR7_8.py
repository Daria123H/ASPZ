import os

for filename in os.listdir('.'):
    if os.path.isfile(filename): 
        answer = input(f"Remove file '{filename}'? (y/n): ")
        if answer.lower() == 'y':
            try:
                os.remove(filename)
                print(f"File '{filename}' remove")
            except Exception as e:
                print(f"Error when deleting a file '{filename}': {e}")
        else:
            print(f"File '{filename}' flooded")
