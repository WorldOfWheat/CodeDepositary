from pwn import *

r = remote('120.114.62.214', 5124)
r.recvlines(12)

for i in range(100):
    print(r.recvline().decode())
    r.recvuntil(':'.encode())
    n = int(r.recvline().decode())
    r.recvuntil('='.encode())
    m = int(r.recvline().decode())

    print(n, ' ', m)

    if (n == 0):
        ans = 3 * (m ** 2) + m + 3
        r.sendline(str(ans).encode())
    if (n == 1):
        ans = 5 * (m ** 2) + 8
        r.sendline(str(ans).encode())
    if (n == 2):
        ans = 4 * (m ** 3) + 6 * m + 6
        r.sendline(str(ans).encode())
    if (n == 3):
        ans = 7 * (m ** 3) + 5 * (m ** 2)
        r.sendline(str(ans).encode())
    if (n == 4):
        ans = m ** 2 + 4 * m + 3
        r.sendline(str(ans).encode())

print(r.recvline().decode());

