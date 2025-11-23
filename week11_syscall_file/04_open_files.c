#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stderr, "Please give two or more arguments\n");
		return 1;
	}

	for (int i = 1; i < argc; ++i) {
		int fd = open(argv[i], O_RDONLY);
		if (fd == -1) {
			perror(argv[i]);
		}
		else {
			printf("%s: Opened successfully\n", argv[i]);
			close(fd);
			printf("%s: Closed successfully\n", argv[i]);
		}
	}

	return 0;
}
