#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define SIZE_BUFFER 1024

int main()
{
    char buffer[SIZE_BUFFER] = {0};
    pid_t pid = 0;
    while (fgets(buffer, SIZE_BUFFER, stdin) != NULL)
    {
        if (buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }
        if ((pid = fork()) < 0)
        {
            perror("error when forking");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            // child
            execlp(buffer, NULL);
        }
        else
        {
            // parent
            int status = 0;
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}