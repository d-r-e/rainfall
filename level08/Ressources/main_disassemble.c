int32_t main(int32_t argc, char** argv, char** envp)
// This function has unresolved stack usage. View graph of stack usage to resolve.

08048591  while (true)
08048591      uint32_t var_a4
08048591      printf(0x8048810, *auth, *service, var_a4)  {"%p, %p \n"}
0804859f      void* var_ac_2 = 0x80
080485ae      void var_90
080485ae      int32_t eax_2 = fgets(&var_90, 0x80, *stdin)
080485b3      eax_2
080485b3      bool c_1 = unimplemented  {test eax, eax}
080485b3      bool z_1 = (eax_2 & eax_2) == 0
080485b5      if (z_1)
080485b5          break
080485c6      int32_t ecx_2 = 5
080485cb      void* esi_1 = &var_90
080485cd      char* edi_1 = data_8048819  {"auth "}
080485cf      while (ecx_2 != 0)
080485cf          char temp0_1 = *esi_1
080485cf          char temp1_1 = *edi_1
080485cf          *esi_1 - *edi_1
080485cf          c_1 = temp0_1 u< temp1_1
080485cf          z_1 = temp0_1 == temp1_1
080485cf          esi_1 = esi_1 + 1
080485cf          edi_1 = edi_1 + 1
080485cf          ecx_2 = ecx_2 - 1
080485cf          if (not(z_1))
080485cf              break
080485dd      int32_t eax_5 = sx.d((not(z_1) && not(c_1)) - c_1)
080485e0      eax_5
080485e0      bool c_2 = unimplemented  {test eax, eax}
080485e0      bool z_2 = (eax_5 & eax_5) == 0
080485e2      if (z_2)
080485f0          *auth = malloc(4)
080485fa          **auth = 0
08048616          int32_t ecx_4 = 0xffffffff
0804861a          void var_8b
0804861a          void* edi_2 = &var_8b
0804861c          while (ecx_4 != 0)
0804861c              bool cond:4_1 = 0 != *edi_2
0804861c              edi_2 = edi_2 + 1
0804861c              ecx_4 = ecx_4 - 1
0804861c              if (not(cond:4_1))
0804861c                  break
08048620          not.d(ecx_4) - 0x1f
08048625          c_2 = not.d(ecx_4) - 1 u< 0x1e
08048625          z_2 = not.d(ecx_4) == 0x1f
08048628          if (not(not(z_2) && not(c_2)))
08048636              var_ac_2 = &var_8b
0804863d              strcpy(*auth, var_ac_2)
0804864d      int32_t ecx_5 = 5
08048652      void* esi_2 = &var_90
08048654      char* edi_3 = data_804881f  {"reset"}
08048656      while (ecx_5 != 0)
08048656          char temp2_1 = *esi_2
08048656          char temp3_1 = *edi_3
08048656          *esi_2 - *edi_3
08048656          c_2 = temp2_1 u< temp3_1
08048656          z_2 = temp2_1 == temp3_1
08048656          esi_2 = esi_2 + 1
08048656          edi_3 = edi_3 + 1
08048656          ecx_5 = ecx_5 - 1
08048656          if (not(z_2))
08048656              break
08048664      int32_t eax_14 = sx.d((not(z_2) && not(c_2)) - c_2)
08048667      eax_14
08048667      bool c_3 = unimplemented  {test eax, eax}
08048667      bool z_3 = (eax_14 & eax_14) == 0
08048669      if (z_3)
08048673          free(*auth, var_ac_2)
08048683      int32_t ecx_7 = 6
08048688      void* esi_3 = &var_90
0804868a      char* edi_4 = data_8048825  {"service"}
0804868c      while (ecx_7 != 0)
0804868c          char temp4_1 = *esi_3
0804868c          char temp5_1 = *edi_4
0804868c          *esi_3 - *edi_4
0804868c          c_3 = temp4_1 u< temp5_1
0804868c          z_3 = temp4_1 == temp5_1
0804868c          esi_3 = esi_3 + 1
0804868c          edi_4 = edi_4 + 1
0804868c          ecx_7 = ecx_7 - 1
0804868c          if (not(z_3))
0804868c              break
0804869a      int32_t eax_18 = sx.d((not(z_3) && not(c_3)) - c_3)
0804869d      eax_18
0804869d      bool c_4 = unimplemented  {test eax, eax}
0804869d      bool z_4 = (eax_18 & eax_18) == 0
0804869f      if (z_4)
080486a5          c_4 = &var_90 u>= 0xfffffff9
080486a5          z_4 = &var_90 == 0xfffffff9
080486b0          void var_89
080486b0          *service = strdup(&var_89, var_ac_2)
080486c0      int32_t ecx_9 = 5
080486c5      void* esi_4 = &var_90
080486c7      char* edi_5 = data_804882d  {"login"}
080486c9      while (ecx_9 != 0)
080486c9          char temp7_1 = *esi_4
080486c9          char temp8_1 = *edi_5
080486c9          *esi_4 - *edi_5
080486c9          c_4 = temp7_1 u< temp8_1
080486c9          z_4 = temp7_1 == temp8_1
080486c9          esi_4 = esi_4 + 1
080486c9          edi_5 = edi_5 + 1
080486c9          ecx_9 = ecx_9 - 1
080486c9          if (not(z_4))
080486c9              break
080486da      if (sx.d((not(z_4) && not(c_4)) - c_4) == 0)
080486ea          if (*(*auth + 32) == 0)
0804870b              var_a4 = *stdout
08048722              fwrite(0x804883b, 1, 0xa, var_a4)  {"Password:\n"}
080486f5          else
080486f5              system(0x8048833, var_ac_2)  {"/bin/sh"}
08048738  return 0
