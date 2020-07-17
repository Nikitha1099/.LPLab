// Copies contents of <source file> into <destination file>

#include<stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * Main function
 * 
 * Usage: copy <source file> <destination file>
 *
*/
int main(int argc, char *argv[]) {
    // Checking if user passes correct arguments.
    if(argc != 3) {
        printf("Invalid arguments.\nUsage: copy <source file> <destination file>\n");
        return -1;
    }

    // Variable declaration
    ssize_t retIn, retOut;
    char buffer[BUF_SIZE];

    // Opening Source file. 
    // int open(const char *pathname, int flags) 
    // If successful, open() returns a non-negative integer, termed a file descriptor.  
    // It returns -1 on failure
    int srcID = open(argv[1], O_RDONLY);
    if(srcID == -1) {
        printf("Unable to open source.txt\n");
        return -1;
    }

    // Opening Destination file
    // int open(const char *pathname, int flags) 
    // If successful, open() returns a non-negative integer, termed a file descriptor.  
    // It returns -1 on failure
    int destID = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if(destID == -1) {
        printf("Unable to open destination.txt\n");
        return -1;
    }

    // Copying data.
    // ssize_t read(int fd, void *buf, size_t count) reads count bytes and stores in buffer
    // and returns number of bytes read
    // 
    // ssize_t write(int fd, const void *buf, size_t count) writes upto count bytes from
    // buffer and returns number of bytes written
    while((retIn = read(srcID, &buffer, BUF_SIZE)) > 0) {
        retOut = write(destID, &buffer, retIn);
        
        if(retOut != retIn) {
            printf("Unable to copy files\n");
            return -1;
        }
    }

    // Closing opened files
    close(srcID);
    close(destID);
    
    printf("Succeccfully copied %s to %s\n", argv[1], argv[2]);
    return 0;
}