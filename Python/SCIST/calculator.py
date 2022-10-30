from pwn import *

r = remote("120.114.62.214", 5119)
r.recvlines(4)

arr = r.recvline().split()

if (int(arr[0]) + int(arr[2]) == arr[4]):
    r.sendline
for i in arr:
    print(i)

