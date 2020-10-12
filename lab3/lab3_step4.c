/*
 * # Name: Joy Zou 
 * # Date: TH 9:15 | 10/11/2020
 * # Title: Lab3 – Step 4
 * # Description: This Program uses a pipe to execlp cat /etc/passwd to upstream and execlp grep root to the downstream
 * */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h> 
//main
int main() {
 	int fds[2];
 	pipe(fds);
	/*child 1 duplicates downstream into stdin */
	if (fork() == 0) {
		dup2(fds[0], 0);
		close(fds[1]);
		execlp("/bin/grep","grep","root",NULL); 
	}
	/*child 2 duplicates upstream into stdout */
	else if (fork() == 0) {
		dup2(fds[1], 1);
		close(fds[0]);
		execlp("/bin/cat", "cat", "/etc/password",NULL); 
	}
	else {  /*parent closes both ends and wait for children*/
		close(fds[0]);
		close(fds[1]);
		wait(0);
		wait(0); 
	}
} 
