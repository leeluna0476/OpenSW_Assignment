#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

extern char **environ;

void sigint_handler(int sig) {
	pid_t child_pid = fork();
	if (child_pid == -1) {
		write(2, "fork error\n", 11);
		exit(1);
	}
	else if (child_pid == 0) {
		char *argv[] = { "ls", NULL };
		execve("/usr/bin/ls", argv, environ);
		write(2, "execve error\n", 13);
		exit(1);
	}
	else {
		int wstatus;
		waitpid(child_pid, &wstatus, 0);
	}
}

void sigquit_handler(int sig) {
	pid_t child_pid = fork();
	if (child_pid == -1) {
		write(2, "fork error\n", 11);
		exit(1);
	}
	else if (child_pid == 0) {
		char *argv[] = { "date", NULL };
		execve("/usr/bin/date", argv, environ);
		write(2, "execve error\n", 13);
		exit(1);
	}
	else {
		int wstatus;
		waitpid(child_pid, &wstatus, 0);
	}
}

void sigalrm_handler(int sig) {
	pid_t child_pid = fork();
	if (child_pid == -1) {
		write(2, "fork error\n", 11);
		exit(1);
	}
	else if (child_pid == 0) {
		char *argv[] = { "whoami", NULL };
		execve("/usr/bin/whoami", argv, environ);
		write(2, "execve error\n", 13);
		exit(1);
	}
	else {
		int wstatus;
		waitpid(child_pid, &wstatus, 0);
		alarm(3);
	}
}

struct sigaction set_sigaction(void (*handler)(int)) {
	struct sigaction int_act;
	int_act.sa_handler = handler;
	sigemptyset(&int_act.sa_mask);
	int_act.sa_flags = 0;

	return int_act;
}

int main(void) {
	struct sigaction int_act = set_sigaction(sigint_handler);
	struct sigaction quit_act = set_sigaction(sigquit_handler);
	struct sigaction alrm_act = set_sigaction(sigalrm_handler);

	sigaction(SIGINT, &int_act, NULL);
	sigaction(SIGQUIT, &quit_act, NULL);
	sigaction(SIGALRM, &alrm_act, NULL);
	alarm(3);
	for (;;);
}

/*
struct sigaction {
    void     (*sa_handler)(int);
    void     (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer)(void);
};

int sigaction(int signum, const struct sigaction *_Nullable restrict act, struct sigaction *_Nullable restrict oldact);
*/
