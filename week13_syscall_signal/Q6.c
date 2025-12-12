#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void) {
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigprocmask(SIG_BLOCK, &set, NULL);
	sleep(5);
	sigset_t pending;
	if (sigpending(&pending) == -1) {
		perror("sigpending");
		return 1;
	}
	else if (sigismember(&pending, SIGINT)) {
		printf("SIGINT is pending\n");
	}
	else {
		printf("SIGINT is not pending\n");
	}
}

/*
int sigprocmask(int how, const sigset_t *_Nullable restrict set, sigset_t *_Nullable restrict oldset);
*/
