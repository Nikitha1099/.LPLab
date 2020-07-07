#include<stdio.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main() {
    int srcID = open("source.txt", O_RDONLY);
    ssize_t ret_in, ret_out;
    char buffer[BUF_SIZE];

    if(srcID == -1) {
        printf("Unable to open source.txt\n");
        return -1;
    }

    int destID = open("destination.txt", O_WRONLY | O_CREAT, 0644);
    if(destID == -1) {
        printf("Unable to open destination.txt\n");
        return -1;
    }

    while((ret_in = read(srcID, &buffer, BUF_SIZE)) > 0) {
        ret_out = write(destID, &buffer, ret_in);
        if(ret_out != ret_in) {
            printf("Unable to copy files\n");
            return -1;
        }
    }

    close(srcID);
    close(destID);

    printf("Copy successful.\n");
    return 1;
}