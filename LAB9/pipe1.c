#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MSG_SIZE 50

int main(){
    int pipefd[2];
    if(pipe(pipefd) == -1){
        perror("pipe");
        exit(1);
    }
    
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }
    
    if(pid == 0){
        // Child process: close unused write end, then read
        close(pipefd[1]);
        char buffer[MSG_SIZE];
        read(pipefd[0], buffer, MSG_SIZE);
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    } else {
        // Parent process: close unused read end, then write
        close(pipefd[0]);
        char msg[] = "Message from Parent via Pipe";
        write(pipefd[1], msg, strlen(msg) + 1);
        close(pipefd[1]);
        wait(NULL);
    }
    return 0;
}
