from pwn import *

r = remote("120.114.62.214", 2400)
r.recvlines(7)

r.recvuntil(b'numbers :')

a = r.recvline().decode()
b = [int(i) for i in a.split()]

b.sort()

r.sendline(str(b[-3]).encode())

print(r.recvline().decode())

