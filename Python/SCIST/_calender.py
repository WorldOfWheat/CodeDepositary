from pwn import *

r = remote("120.114.62.214", 2402)
r.recvlines(9)

for i in range(100):
    r.recvline()
    r.recvuntil("year :".encode())
    a = r.recvline().decode();
    a = int(a)
    if ((a % 4 == 0 and a % 100 != 0) or (a % 400 == 0)):
        print("leap")
        r.sendlineafter("answer : ".encode(),  "leap".encode())
    else:
        print("ordinary")
        r.sendlineafter("answer : ".encode(), "ordinary".encode())
    
print(r.recvline().decode())

