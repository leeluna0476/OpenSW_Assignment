#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 128

int main(void) {
	char buf[BUFSIZE];
	while (42) {
		ssize_t read_bytes = read(0, buf, BUFSIZE);
		if (!read_bytes) {
			break;
		}
		write(1, buf, read_bytes);
	}

	return 0;
}
