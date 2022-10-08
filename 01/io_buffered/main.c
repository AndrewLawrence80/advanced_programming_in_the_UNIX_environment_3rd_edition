#include <stdio.h>
int main()
{
    int val_get = 0;
    while ((val_get = getc(stdin)) != EOF)
    {
        putc(val_get, stdout);
    }
    return 0;
}