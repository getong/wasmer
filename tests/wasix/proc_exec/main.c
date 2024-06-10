#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc > 1 && argv[1] != NULL)
    {
        return 0;
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        char *newargv[] = {argv[0], "child", NULL};

        execv("/code/main.wasm", newargv);

        exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
        printf("%d", status);
    }

    return 0;
}