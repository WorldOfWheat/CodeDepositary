from pwn import *

r = remote('120.114.62.214', 5127)

r.recvlines(5)

for i in range(100):
    r.recvline();
    r.recvuntil(':'.encode())

    n = int(r.recvline());
    
    n = (n  - 32) * 5

    ans = str(n) + str('/9')

    print(ans)
    r.sendline(ans.encode())

print(r.recvline().decode())
