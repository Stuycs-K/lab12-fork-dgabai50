#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>


int err(){
    printf("errno %d: Err Message: %s\n",errno,strerror(errno));
    exit(1);
}

int main() {
	printf("%d about to create 2 child processes\n", getpid());

	pid_t p1, p2;
	p1 = fork();
	//p2 = fork();

	if (p1 < 0) {
		perror("fork failed");
		exit(1);
	} else if (p1 == 0) {
		int r;
		
		int file = open("/dev/urandom", O_RDONLY, 0);
		int r_file = read(file, &r, 4);
		if (r_file == -1) err();
		close(file);

		if (r < 0) r *= -1;
		r = r % 5 + 1;
		printf("%d\n", r);
	}
}
