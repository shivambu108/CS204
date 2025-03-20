#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MSG_SIZE 50

int main(){
    int pipe1[2]; // Pipe for Parent -> Child
    int pipe2[2]; // Pipe for Child -> Parent

    if(pipe(pipe1) == -1 || pipe(pipe2) == -1){
        perror("pipe");
        exit(1);
    }
    
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }
    
    if(pid == 0){
        // Child process
        // Close unused ends
        close(pipe1[1]); // child does not write to pipe1
        close(pipe2[0]); // child does not read from pipe2
        
        // Read message from parent
        char buffer[MSG_SIZE];
        read(pipe1[0], buffer, MSG_SIZE);
        printf("Child received: %s\n", buffer);
        
        // Send reply to parent
        char reply[] = "Reply from Child via Pipe";
        write(pipe2[1], reply, strlen(reply) + 1);
        
        close(pipe1[0]);
        close(pipe2[1]);
    } else {
        // Parent process
        // Close unused ends
        close(pipe1[0]); // parent does not read from pipe1
        close(pipe2[1]); // parent does not write to pipe2
        
        // Send message to child
        char msg[] = "Message from Parent via Pipe";
        write(pipe1[1], msg, strlen(msg) + 1);
        
        // Read reply from child
        char buffer[MSG_SIZE];
        read(pipe2[0], buffer, MSG_SIZE);
        printf("Parent received: %s\n", buffer);
        
        close(pipe1[1]);
        close(pipe2[0]);
        wait(NULL);
    }
    return 0;
}
