#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
	
	mkfifo("fifoPipe", 0666); 
	int fd = open("fifoPipe", O_WRONLY);
	char* s = "Greetings from PipeWriter";
	while(1) {
	    write(fd, s, strlen(s));
	    sleep(1);
	}
	return 0;
}
