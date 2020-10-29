import sys
from cs50 import get_string

if len(sys.argv) != 2:
    print("Usage: python caesar.py k")
    sys.exit(1)

k = int(sys.argv[1])

plaintext = get_string("plaintext: ")
print("ciphertext: ", end='')

for i in plaintext:
    if not i.isalpha():
        print(i, end='')
        continue
    type = ord('A') if i.isupper() else ord('a')
    print(chr((((ord(i) - type) + k) % 26) + type), end='')
    
print()