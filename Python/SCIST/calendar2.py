from pwn import *

r = remote("120.114.62.214", 2402)
r.recvlines(10)

print(r.recvline().decode())
