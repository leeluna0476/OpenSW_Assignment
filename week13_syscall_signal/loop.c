#include <stdio.h>
#include <unistd.h>

int main(void) {
	for (;;) {
		printf("pid: %u\n", getpid());
		sleep(1);
	}
}
