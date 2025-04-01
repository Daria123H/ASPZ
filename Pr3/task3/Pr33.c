#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>

#include <sys/stat.h>

#define FILENAME "PR3_31.txt"  

#define MAX_FILE_SIZE 1024   

#define BATCH_SIZE 100 

int cube() {

    return (arc4random() % 6) + 1;
    
}

int main() {

    int fd;
    
    struct stat file_stat;
    
    char buffer[BATCH_SIZE * 3];  
    
    fd = open(FILENAME, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    
    if (fd == -1) {
    
        perror("Trouble to open file");
        
        return EXIT_FAILURE;
        
    }
    
    while (1) {
    
        if (stat(FILENAME, &file_stat) == -1) {
        
            perror("Trouble to take size file");
            
            close(fd);
            
            return EXIT_FAILURE;
            
        }
        
        if (file_stat.st_size >= MAX_FILE_SIZE) {
        
            printf("The maximum file size has been reached. End of work.\n", MAX_FILE_SIZE);
            
            break;
            
        }
        
        int pos = 0;
        
        for (int i = 0; i < BATCH_SIZE; i++) {
        
            pos += snprintf(buffer + pos, sizeof(buffer) - pos, "%d\n", roll_dice());
            
        }
        
        if (file_stat.st_size + pos > MAX_FILE_SIZE) {
        
            printf("If the recording exceeds the file limit, we stop working.\n");
            
            break;
            
        }
        
        if (write(fd, buffer, pos) == -1) {
        
            perror("Trouble to recording in file");
            
            close(fd);
            
            return EXIT_FAILURE;
            
        }
        
        printf("Write %d rolls\n", BATCH_SIZE);
        
    }
    
    close(fd);
    
    return EXIT_SUCCESS;
    
}
