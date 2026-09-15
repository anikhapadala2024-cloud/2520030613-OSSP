#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int signal_number)
{
    printf("\nSIGINT received.\n");
    printf("Signal handler executed successfully.\n");
    printf("Program terminating safely.\n");
    exit(0);
}

int main()
{
    signal(SIGINT, handle_signal);

    printf("Signal handling program started.\n");
    printf("Press Ctrl+C to send SIGINT.\n");

    while (1)
    {
        printf("Program is running...\n");
        sleep(2);
    }

    return 0;
}

