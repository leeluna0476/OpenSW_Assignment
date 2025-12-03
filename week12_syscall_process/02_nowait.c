#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void) {
	pid_t child_pid = fork();
	if (child_pid == -1) {
		perror("fork");
		return 1;
	}
	else if (child_pid == 0) {
		sleep(1);
		printf("Child process pid: %u ppid: %u\n", getpid(), getppid());
		return 7;
	}
	else {
		printf("Parent process pid: %u ppid: %u\n", getpid(), getppid());
		return 0;
	}
}
