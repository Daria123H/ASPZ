import sys

def show_file(filename):
    try:
        with open(filename) as f:
            for i, line in enumerate(f, 1):
                print(line, end='')
                if i % 20 == 0:
                    input("Press Enter to continue")
    except Exception as e:
        print(f"Erore with file {filename}: {e}")

if len(sys.argv) < 2:
    print("Result")
else:
    for fname in sys.argv[1:]:
        print(f"\n=== {fname} ===")
        show_file(fname)
