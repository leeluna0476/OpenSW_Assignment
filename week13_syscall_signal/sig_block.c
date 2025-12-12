#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct two_double {
	double a;
	double b;
} data;

void sigalrm_handler(int _signo) {
	printf("%f, %f\n", data.a, data.b);
	alarm(1);
}

int main(void) {
	struct sigaction sa_sigalrm;
	struct two_double zeros = { 0.0, 0.0 }, ones = { 1.0, 1.0 };

	sa_sigalrm.sa_handler = sigalrm_handler;
	sigemptyset(&sa_sigalrm.sa_mask);
	sigaddset(&sa_sigalrm.sa_mask, SIGALRM);

	sa_sigalrm.sa_flags = 0;
	if (sigaction(SIGALRM, &sa_sigalrm, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}

	alarm(1);
	while (42) {
		sigprocmask(SIG_BLOCK, &sa_sigalrm.sa_mask, NULL);
		data = zeros;
		sigprocmask(SIG_UNBLOCK, &sa_sigalrm.sa_mask, NULL);

		sigprocmask(SIG_BLOCK, &sa_sigalrm.sa_mask, NULL);
		data = ones;
		sigprocmask(SIG_UNBLOCK, &sa_sigalrm.sa_mask, NULL);
	}

	return 0;
}

/*
int sigprocmask(int how, const sigset_t *_Nullable restrict se t, sigset_t *_Nullable restrict oldset
);
*/
