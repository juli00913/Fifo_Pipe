#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int fd = open("fifoPipe", O_RDONLY);
    char buff[26];	
    while(read(fd, buff, 26)) {
        write(STDOUT_FILENO, buff, 26);
        write(STDOUT_FILENO, "\n", 1);
    }
    close(fd);
    return 0;
}
