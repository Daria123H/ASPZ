#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("PR8.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }

    unsigned char data[] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};
    write(fd, data, sizeof(data));
    close(fd);

    return 0;
}
