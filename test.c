#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#ifndef MAX_BUF
#define MAX_BUF 200
#endif

int main(void) {
    char path[MAX_BUF];

    errno = 0;
    if (getcwd(path, MAX_BUF) == NULL) {
        if (errno == ERANGE)
            printf("[ERROR] pathname length exceeds the buffer size\n");
        else
            perror("getcwd");
        exit(EXIT_FAILURE);
    }
    printf("Current working directory: %s\n", path);

    exit(EXIT_SUCCESS);
}