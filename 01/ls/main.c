#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    if (argc != 2)
    {
        perror("usage: ls [dir_name]");
        exit(EXIT_FAILURE);
    }
    else
    {
        if ((dp = opendir(argv[1])) == NULL)
        {
            char msg[1024] = {0};
            sprintf(msg, "can't open %s", argv[1]);
            perror(msg);
            exit(EXIT_FAILURE);
        }
        else
        {
            while ((dirp = readdir(dp)) != NULL)
            {
                printf("%s\n", dirp->d_name);
            }
            closedir(dp);
        }
    }
    return 0;
}