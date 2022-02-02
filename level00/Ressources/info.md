there is a binary executable "level0" in home folder

    scp -P 4242 level0@10.11.200.132:/home/user/level0/level0 .

Reverse engineering it (with Ghydra or Binary Ninja) shows it checks that argv1 is equal to 423 and then it executes a shell
"/bin/sh" as level1
```
int32_t main(void* arg1)

08048ed9  if (atoi(*(arg1 + 4)) != 423)
08048f7b      fwrite(0x80c5350, 1, 5, *_IO_stderr)  {"No !\n"}
08048eec  else
08048eec      char* var_20 = strdup("/bin/sh")
08048ef8      int32_t eax_5 = __getegid()
08048f01      int32_t eax_6 = __geteuid()
08048f21      setresgid(eax_5, eax_5, eax_5)
08048f3d      __setresuid(eax_6, eax_6, eax_6)
08048f51      execv(0x80c5348, &var_20)  {"/bin/sh"}
08048f86  return 0
```

Therefore:

```
./level0 423
whoami
cat /home/user/level1/.pass
```
