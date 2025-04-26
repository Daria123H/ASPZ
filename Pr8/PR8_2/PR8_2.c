// read.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("PR8_2.bin", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    unsigned char buffer[4];

    if (lseek(fd, 3, SEEK_SET) == -1) {
        perror("Error seeking file");
        close(fd);
        return 1;
    }

    if (read(fd, buffer, 4) != 4) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        printf("%u ", buffer[i]);
    }
    printf("\n");

    close(fd);
    return 0;
}
