#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();   // Create child process

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        // CHILD process
        printf("Child process running 'ls' using exec...\n");
        execl("/bin/ls", "ls", "-l", NULL);  
        perror("exec failed"); // If exec fails
        exit(1);
    }
    else {
        // PARENT process
        printf("Parent process, child PID = %d\n", pid);
        wait(NULL); // Wait for child
        printf("Child finished execution.\n");
    }

    return 0;
}
