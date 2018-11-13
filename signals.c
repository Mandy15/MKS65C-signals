#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

static void sighandler(int signo){
  if(signo == SIGUSR1){
		printf("PID of parent process: %d\n", getppid());
	}else if(signo == SIGINT){
    int fd = open("sigint.txt", O_WRONLY | O_APPEND);
    write(fd, "Program exited due to SIGINT.\n", 32);
    close(fd);
    // printf("Check file for end, SIGINT \n");
		exit(0);
	}
}

int main(){
  signal(SIGUSR1, sighandler);
  signal(SIGINT, sighandler);
	while(1){
		printf("PID: %d\n", getpid());
		sleep(1);
	}
	return 0;
}
