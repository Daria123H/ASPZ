import sys

import os

import shutil

def copy_file(src, dest):
  
    if len(sys.argv) != 3:
      
        print("Program need two arguments")
      
        sys.exit(1)

    if not os.path.isfile(src) or not os.access(src, os.R_OK):
      
        print(f"Cannot open file {src} for reading")
      
        sys.exit(1)

    if os.path.exists(dest) and not os.access(dest, os.W_OK):
      
        print(f"Cannot open file {dest} for writing")
      
        sys.exit(1)

    try:
      
        shutil.copy2(src, dest)
      
        print(f"File {src} copied to {dest}")
      
    except shutil.SameFileError:
      
        print("Source and destination files are the same")
      
    except OSError as e:
      
        print(f"Error copying file: {e}")
      
        if "File too large" in str(e):
          
            print("File size limit exceeded")
          
        sys.exit(1)

if __name__ == "__main__":
  
    copy_file(sys.argv[1], sys.argv[2])
