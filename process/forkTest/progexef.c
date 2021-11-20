#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define ERR -1
void usage(void);
char *comman_name;
int main(int argc, char *argv[])
{
    pid_t pid;
    int status;
   // char *rindex(const char *s, int c);

    if ((comman_name = rindex(argv[0], '/')) != NULL)
        comman_name++;
    else
        comman_name = argv[0];
    if (argc < 2)
        usage();
    if ((pid = fork()) == 0)
    {
        //子プロセスの処理
        printf("Child process : execute a new program %s.\n", argv[1]);
        if (execv(argv[1], &argv[1]) == ERR)
        {
            perror("execvp");
            exit(1);
        }
    }
    else if (pid >= 1)
    {
        wait(&status);
        printf("Parent process : child process has just finished.\n");
        printf("status = %04x\n", status);
    }
    else
    {
        perror("fork");
        exit(1);
    }
    exit(0);
}
void usage(void)
{
    fprintf(stderr, "Usage: %s command [option]\n", comman_name);
    exit(1);
}