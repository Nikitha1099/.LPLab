// Creates a file named "close-on-evec.txt" with permissions 666 and close-on-evec flag set.

#include<stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * Main Function
 * 
 * Usage: close_on_exec
 *  
*/
int main(void) {
    // Creating "close-on-evec.txt" with permissions 666 and close-on-evec flag set.
    // int open(const char *pathname, int flags) 
    // If successful, open() returns a non-negative integer, termed a file descriptor.  
    // It returns -1 on failure
    int fd;
    if((fd = open("close-on-exec.txt", O_WRONLY|O_CREAT, 0666)) == -1) {
        printf("Unable to open the file.");
    }
    
    // Retriving old flags of the file (in this case, the flags set during creation)
    // int fcntl(int fildes, int cmd, ...);
    // Upon successful completion, the value returned depends on cmd
    // Otherwise, a value of -1 is returned
    int old_flags = fcntl(fd, F_GETFD);
    printf("Old flags: %d\n", old_flags);

    fcntl(fd, F_SETFD, FD_CLOEXEC);

    // Retriving new flags of the file
    int new_flags = fcntl(fd, F_GETFD);
    printf("New flags: %d\n", new_flags);
    
    return  0;
}