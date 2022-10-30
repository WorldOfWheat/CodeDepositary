from pwn import *

r = remote("120.114.62.214", 5119)

r.recvlines(3)

for i in range(100):

    r.recvlines(1)
    arr = r.recvline().split()

    for j in arr:
        print(j)

    if (int(arr[0]) + int(arr[2]) == int(arr[4])):
        r.sendlineafter('?', '+')
    if (int(arr[0]) - int(arr[2]) == int(arr[4])):
        r.sendlineafter('?', '-')
    if (int(arr[0]) * int(arr[2]) == int(arr[4])):
        r.sendlineafter('?', '*')

print(r.recvline().decode())
