#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_NAME "myfifo"

int main()
{
    int fd;
    char message[100];

    printf("Enter message for server: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    fd = open(FIFO_NAME, O_WRONLY);

    write(fd, message, strlen(message) + 1);

    printf("Client sent: %s\n", message);

    close(fd);

    return 0;
}

