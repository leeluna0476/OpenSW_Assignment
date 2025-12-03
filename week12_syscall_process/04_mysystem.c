#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int mysystem(const char *cmd) {
	pid_t child = fork();
	if (child == -1) {
		perror("fork");
		return -1;
	}
	else if (child == 0) {
		execl("/bin/sh", "sh", "-c", cmd, NULL);
		return -1;
	}
	else {
		int wstatus;
		waitpid(child, &wstatus, 0);
		return 1;
	}
}

int main(void) {
	mysystem("ls -l | wc -l");
	mysystem("find . -name '*.c'");
}
