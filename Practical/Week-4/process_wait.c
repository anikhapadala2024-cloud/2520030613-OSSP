#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t child1, child2;
    int status;

    printf("Parent process started.\n");
    printf("Parent PID: %d\n", getpid());

    child1 = fork();

    if (child1 < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (child1 == 0)
    {
        printf("\nChild 1\n");
        printf("Child 1 PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(2);

        printf("Child 1 completed.\n");
        exit(10);
    }

    child2 = fork();

    if (child2 < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (child2 == 0)
    {
        printf("\nChild 2\n");
        printf("Child 2 PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(4);

        printf("Child 2 completed.\n");
        exit(20);
    }

    printf("\nParent waiting for children...\n");

    waitpid(child1, &status, 0);
    printf("Parent detected termination of Child 1.\n");

    waitpid(child2, &status, 0);
    printf("Parent detected termination of Child 2.\n");

    printf("\nParent process completed.\n");

    return 0;
}

