import os

def child_process(message):
    print(f"Child process: {message}")
    os._exit(0)  # вихід з дочірнього процесу

def main():
    # Створюємо перший дочірній процес
    pid1 = os.fork()
    if pid1 == 0:
        child_process("Hello from first process!")
    
    # Створюємо другий дочірній процес
    pid2 = os.fork()
    if pid2 == 0:
        child_process("Hello from second process!")
    
    # Батьківський процес чекає завершення обох
    os.waitpid(pid1, 0)
    os.waitpid(pid2, 0)
    print("Parental process")

if __name__ == "__main__":
    main()
