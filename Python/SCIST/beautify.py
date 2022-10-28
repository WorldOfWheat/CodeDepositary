from pwn import *

#8
#sentence :

r = remote("120.114.62.214", 2401)
r.recvlines(8)

r.recvuntil("sentence : ".encode())

a = r.recvline().decode()
b = ""

for i in a:
    if (i == '-' or i == '_'or i == ' '):
        b = b + ' '
        continue;
    b = b + i.lower()

print(b)
r.sendline(b.encode())

print(r.recvline().decode())
print(r.recvline().decode())
