import subprocess
import os

result = subprocess.run(['getent', 'passwd'], capture_output=True, text=True)
lines = result.stdout.strip().split('\n')

current_user = os.getlogin()
found = False

for line in lines:
    parts = line.split(':')
    username = parts[0]
    uid = int(parts[2])

   if uid >= 1000 and username != current_user and username != "nobody":
        print(f"Another regular user found: {username} (UID: {uid})")
        found = True


if not found:
    print("No other regular users found.")
