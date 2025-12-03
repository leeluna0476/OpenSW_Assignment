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
		printf("Child process pid: %u ppid: %u\n", getpid(), getppid());
		return 7;
	}
	else {
		printf("Parent process pid: %u ppid: %u\n", getpid(), getppid());
		int wstatus;
		waitpid(child_pid, &wstatus, 0);
		if (WIFEXITED(wstatus)) {
			printf("Child process %u exit code: %d\n", child_pid, WEXITSTATUS(wstatus));
		}
		return 0;
	}
}
