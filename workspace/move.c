// Moves <source file> into <destination file>

#include<stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * Main function
 * 
 * Usage: move <source file> <destination file>
 *
*/
int main(int argc, char *argv[]) {
    // Checking if user passes correct arguments.
    if(argc != 3) {
        printf("Invalid arguments.\nUsage: copy <source file> <destination file>\n");
        return -1;
    }

    // Linking source file to destination file.
    // int link(const char *oldpath, const char *newpath) creates a new link to an existing file.
    // On success, 0 is returned.  On error, -1 is returned
    if((link(argv[1], argv[2])) == -1) {
        printf("Unable to move file: %s\n", argv[1]);
        return -1;
    }

    // Unlinking Source file (removing original file).
    // int unlink(const char *pathname) deletes a name from the filesystem. If that name was the 
    // last link to a file, the file is deleted.
    // 
    // On success, 0 is returned.  On error, -1 is returned.
    if((unlink(argv[1])) == -1) {
        printf("Unable to move file: %s\n", argv[1]);

        // Rolling back changes to prevent any sideeffects.
        unlink(argv[2]);
        return -1;
    }

    printf("Succeccfully moved %s to %s\n", argv[1], argv[2]);
    return 0;
}