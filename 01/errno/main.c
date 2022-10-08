#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(const int argc, const char *argv[])
{
    fprintf(stderr, "EACESS:%s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    return 0;
}