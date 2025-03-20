#include <stdio.h>      // For printf(), perror()
#include <stdlib.h>     // For exit()
#include <unistd.h>     // For pipe(), fork(), read(), write(), close()
#include <string.h>     // For strlen()
#include <sys/wait.h>   // For wait()

#define MSG_SIZE 50     // Define the size for our message buffer

int main(){
    int pipefd[2]; // Array to hold the two file descriptors for the pipe
    // Create the pipe. pipefd[0] is for reading, pipefd[1] is for writing.
    if(pipe(pipefd) == -1){
        perror("pipe");
        exit(1);
    }
    
    // Fork the process into parent and child.
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }
    
    if(pid == 0){
        // Child process
        close(pipefd[1]);  // Close the write end, child only reads.
        char buffer[MSG_SIZE];
        // Read message from the pipe.
        read(pipefd[0], buffer, MSG_SIZE);
        // Print the message received.
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);  // Close the read end.
    } else {
        // Parent process
        close(pipefd[0]);  // Close the read end, parent only writes.
        char msg[] = "Message from Parent via Pipe";
        // Write the message into the pipe (include the null terminator).
        write(pipefd[1], msg, strlen(msg) + 1);
        close(pipefd[1]);  // Close the write end to indicate end-of-file.
        wait(NULL);        // Wait for the child process to finish.
    }
    return 0;
}
