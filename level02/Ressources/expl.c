#include <string.h>
#include <stdio.h>

int main()
{
    char *p = getenv("EXPLOIT");
    printf("%p\n", p);
    return(0);
}