#include <stdio.h>      // For printf(), perror()
#include <stdlib.h>     // For exit()
#include <sys/ipc.h>    // For IPC (Inter-Process Communication) keys and permissions
#include <sys/shm.h>    // For shared memory functions: shmget(), shmat(), shmdt(), shmctl()
#include <string.h>     // For strcpy()
#include <unistd.h>     // For sleep()

#define SHM_SIZE 1024   // Define the size of the shared memory segment

int main(){
    key_t key = 1234; // Key to uniquely identify the shared memory segment
    // Create a shared memory segment with the given key, size, and permissions.
    // IPC_CREAT ensures that if the segment does not exist, it will be created.
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if(shmid < 0){
        perror("shmget"); // Print error if shmget fails
        exit(1);
    }
    // Attach the shared memory segment to the process's address space.
    char *shm = (char *) shmat(shmid, NULL, 0);
    if(shm == (char *) -1){
        perror("shmat"); // Print error if shmat fails
        exit(1);
    }
    // Write a message into the shared memory.
    strcpy(shm, "Message from Sender");
    printf("Sender: Message written to shared memory.\n");
    
    // Wait for the receiver to acknowledge by changing the shared memory content.
    while(strcmp(shm, "Message from Sender") == 0){
        sleep(1); // Polling: Check every second until the content is changed
    }
    printf("Sender: Acknowledgment received. Exiting.\n");
    
    // Detach the shared memory segment from the process's address space.
    shmdt(shm);
    // Mark the shared memory segment for removal.
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
