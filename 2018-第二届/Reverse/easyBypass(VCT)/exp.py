#coding:utf-8
from pwn import *
context.log_level = 'debug'
p = process("./easyBypass")

p.recvuntil("the flag")

payload = chr(5) + 'AAA' + chr(2) + 'AAA' + chr(0x44) + 'AAA' + chr(0x70)
p.sendline(payload)

p.interactive()


