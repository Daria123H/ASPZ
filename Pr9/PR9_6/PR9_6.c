#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void check_permissions(const char *filename) {
    struct stat file_stat;
    
    if (stat(filename, &file_stat) == -1) {
        perror("stat");
        return;
    }

    printf("File: %s\n", filename);
  
    printf("Permissions: ");
    printf( (file_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (file_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (file_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (file_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (file_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (file_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (file_stat.st_mode & S_IROTH) ? "r" : "-");
    printf( (file_stat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (file_stat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    if (access(filename, R_OK) == 0) {
        printf("Readable\n");
    } else {
        printf("Not readable\n");
    }

    if (access(filename, W_OK) == 0) {
        printf("Writable\n");
    } else {
        printf("Not writable\n");
    }

    if (access(filename, X_OK) == 0) {
        printf("Executable\n");
    } else {
        printf("Not executable\n");
    }
}

void list_directory(const char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }

        char filename[512];
        snprintf(filename, sizeof(filename), "%s/%s", path, entry->d_name);
        check_permissions(filename);
    }

    closedir(dir);
}

int main() {
    printf("Home directory:\n");
    list_directory(getenv("HOME"));

    printf("\n/usr/bin directory:\n");
    list_directory("/usr/bin");
  
    printf("\n/etc directory:\n");
    list_directory("/etc");

    return 0;
}

