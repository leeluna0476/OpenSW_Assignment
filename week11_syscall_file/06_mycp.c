#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 32

int main(int argc, char **argv) {
	if (argc < 3) {
		fprintf(stderr, "Usage: ./mycp [source file] [destination file]*n\n");
		return 1;
	}

	int src_fd = open(argv[1], O_RDONLY);
	if (src_fd == -1) {
		perror(argv[1]);
		return 1;
	}

	int dest_fileno = argc - 2;
	int *dest_fds = (int *)malloc(sizeof(int) * (dest_fileno));
	if (!dest_fds) {
		perror("malloc");
		close(src_fd);
		return 1;
	}
	
	for (int i = 0; i < dest_fileno; ++i) {
		dest_fds[i] = open(argv[i + 2], O_WRONLY | O_CREAT, 0644);
		if (dest_fds[i] == -1) {
			perror(argv[i + 2]);
		}
	}

	char buf[BUFSIZE];
	while (42) {
		ssize_t read_bytes = read(src_fd, buf, BUFSIZE);
		if (!read_bytes) {
			break;
		}

		write(1, buf, read_bytes);
		for (int i = 0; i < dest_fileno; ++i) {
			if (dest_fds[i] != -1) {
				write(dest_fds[i], buf, read_bytes);
			}
		}
	}

	for (int i = 0; i < dest_fileno; ++i) {
		if (dest_fds[i] != -1) {
			close(dest_fds[i]);
		}
	}
	free(dest_fds);
	
	close(src_fd);
}
