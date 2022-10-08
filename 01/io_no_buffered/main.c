#include <stdio.h>
#include <unistd.h>
#define SIZE_BUFFER 1024
int main()
{
    char buffer[SIZE_BUFFER] = {0};
    int val_read = 0;
    while ((val_read = read(STDIN_FILENO, buffer, SIZE_BUFFER)) > 0)
    {
        write(STDOUT_FILENO, buffer, val_read);
    }
    return 0;
}