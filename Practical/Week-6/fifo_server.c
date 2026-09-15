#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_NAME "myfifo"

int main()
{
    int fd;
    char buffer[100];

    mkfifo(FIFO_NAME, 0666);

    printf("FIFO Server started.\n");
    printf("Waiting for client message...\n");

    fd = open(FIFO_NAME, O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Server received: %s\n", buffer);

    close(fd);

    unlink(FIFO_NAME);

    printf("FIFO Server completed.\n");

    return 0;
}
