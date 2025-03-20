#include <stdio.h>      // For printf(), perror()
#include <stdlib.h>     // For exit()
#include <sys/ipc.h>    // For IPC keys
#include <sys/shm.h>    // For shared memory functions: shmget(), shmat(), shmdt()
#include <string.h>     // For strcpy()
#include <unistd.h>     // For sleep()

#define SHM_SIZE 1024   // Define the size of the shared memory segment

int main(){
    key_t key = 1234; // Use the same key as the sender to locate the segment
    // Locate the existing shared memory segment using the same key.
    int shmid = shmget(key, SHM_SIZE, 0666);
    if(shmid < 0){
        perror("shmget"); // Print error if shmget fails
        exit(1);
    }
    // Attach the shared memory segment to this process.
    char *shm = (char *) shmat(shmid, NULL, 0);
    if(shm == (char *) -1){
        perror("shmat"); // Print error if shmat fails
        exit(1);
    }
    // Read the message from shared memory and print it.
    printf("Receiver: Read message: %s\n", shm);
    
    // Send an acknowledgment by modifying the shared memory content.
    strcpy(shm, "ACK");
    printf("Receiver: Acknowledgment sent.\n");
    
    // Detach the shared memory segment.
    shmdt(shm);
    return 0;
}
