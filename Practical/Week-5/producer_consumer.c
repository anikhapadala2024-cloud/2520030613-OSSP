#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int pipefd[2];
    pid_t pid;
    char buffer[100];

    if (pipe(pipefd) == -1)
    {
        perror("pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        close(pipefd[1]);

        read(pipefd[0], buffer, sizeof(buffer));

        printf("Consumer received: %s\n", buffer);

        close(pipefd[0]);
    }
    else
    {
        close(pipefd[0]);

        strcpy(buffer, "Hello from Producer!");

        write(pipefd[1], buffer, strlen(buffer) + 1);

        printf("Producer sent: %s\n", buffer);

        close(pipefd[1]);
    }

    return 0;
}
