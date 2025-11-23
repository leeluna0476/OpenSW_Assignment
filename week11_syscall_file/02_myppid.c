#include <unistd.h>
#include <stdio.h>

int main(void) {
	printf("pid: %u\n", getpid());
	printf("ppid: %u\n", getppid());
}
