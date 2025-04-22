#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define NUM_LINES 10
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usege: %s <PR8_21>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("File could not be opened");
        return 1;
    }

    off_t file_size = lseek(fd, 0, SEEK_END);
    off_t offset = file_size - 1;
    char c;
    int lines = 0;

    while (offset >= 0 && lines < NUM_LINES) {
        lseek(fd, offset, SEEK_SET);
        read(fd, &c, 1);
        if (c == '\n') lines++;
        offset--;
    }

    char buf[BUF_SIZE];
    ssize_t bytes_read;
    while (offset < file_size) {
        lseek(fd, offset + 1, SEEK_SET); 
        bytes_read = read(fd, buf, sizeof(buf) - 1);
        if (bytes_read > 0) {
            buf[bytes_read] = '\0';
            write(STDOUT_FILENO, buf, bytes_read);
        }
        offset += bytes_read;
    }

    lseek(fd, 0, SEEK_END);

    while (1) {
        if (read(fd, buf, sizeof(buf)) > 0) {
            write(STDOUT_FILENO, buf, sizeof(buf));
        } else {
            sleep(1);
        }
    }

    close(fd);
    return 0;
} 



