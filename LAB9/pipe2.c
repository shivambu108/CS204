#include <stdio.h>      // For printf(), perror()
#include <stdlib.h>     // For exit()
#include <unistd.h>     // For pipe(), fork(), read(), write(), close()
#include <string.h>     // For strlen()
#include <sys/wait.h>   // For wait()

#define MSG_SIZE 50     // Define the size for our message buffers

int main(){
    int pipe1[2]; // Pipe for communication from Parent to Child
    int pipe2[2]; // Pipe for communication from Child to Parent

    // Create both pipes. Each pipe returns two file descriptors.
    if(pipe(pipe1) == -1 || pipe(pipe2) == -1){
        perror("pipe");
        exit(1);
    }
    
    // Fork to create parent and child processes.
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }
    
    if(pid == 0){
        // Child process
        
        // Close unused ends: Child will read from pipe1 and write to pipe2.
        close(pipe1[1]); // Child does not write to pipe1.
        close(pipe2[0]); // Child does not read from pipe2.
        
        char buffer[MSG_SIZE];
        // Read message from parent via pipe1.
        read(pipe1[0], buffer, MSG_SIZE);
        printf("Child received: %s\n", buffer);
        
        // Prepare a reply message.
        char reply[] = "Reply from Child via Pipe";
        // Write the reply into pipe2 so parent can read it.
        write(pipe2[1], reply, strlen(reply) + 1);
        
        // Close the used ends.
        close(pipe1[0]);
        close(pipe2[1]);
    } else {
        // Parent process
        
        // Close unused ends: Parent will write to pipe1 and read from pipe2.
        close(pipe1[0]); // Parent does not read from pipe1.
        close(pipe2[1]); // Parent does not write to pipe2.
        
        char msg[] = "Message from Parent via Pipe";
        // Write message to child using pipe1.
        write(pipe1[1], msg, strlen(msg) + 1);
        
        char buffer[MSG_SIZE];
        // Read the child's reply from pipe2.
        read(pipe2[0], buffer, MSG_SIZE);
        printf("Parent received: %s\n", buffer);
        
        // Close the used ends.
        close(pipe1[1]);
        close(pipe2[0]);
        wait(NULL); // Wait for the child process to finish.
    }
    return 0;
}
