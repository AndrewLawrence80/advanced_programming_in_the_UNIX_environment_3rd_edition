#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("pid %ld", (long)getpid());
    return 0;
}