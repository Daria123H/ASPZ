#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[] = "Hello, this is a test!";
    int fd = open("testfile.txt", O_WRONLY | O_CREAT, 0644);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    ssize_t count = write(fd, buffer, sizeof(buffer) - 1);
    if (count == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    printf("Attempted to write %zu bytes, but wrote %zd bytes\n", sizeof(buffer) - 1, count);

    close(fd);
    return 0;
}
