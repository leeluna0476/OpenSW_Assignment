#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp) {
	if (argc < 2) {
		fprintf(stderr, "Usage: ./03_execve <program path> [OPTION]...\n");
		return 1;
	}

	pid_t child = fork();
	if (child == -1) {
		perror("fork");
		return 1;
	}
	else if (child == 0) {
		char **args = (char **)malloc(sizeof(char *) * argc);
		if (!args) {
			perror("malloc");
			return 1;
		}
		for (int i = 1; i < argc; ++i) {
			args[i - 1] = argv[i];
		}
		args[argc - 1] = NULL;
		execve(argv[1], args, envp);
		return 1;
	}
	else {
		int wstatus;
		waitpid(child, &wstatus, 0);
		if (WIFEXITED(wstatus)) {
			printf("child exited with status: %d\n", WEXITSTATUS(wstatus));
		}
		return 0;
	}
}
