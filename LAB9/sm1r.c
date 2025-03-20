#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main(){
    key_t key = 1234; // same key as sender
    int shmid = shmget(key, SHM_SIZE, 0666);
    if(shmid < 0){
        perror("shmget");
        exit(1);
    }
    char *shm = (char *) shmat(shmid, NULL, 0);
    if(shm == (char *) -1){
        perror("shmat");
        exit(1);
    }
    // Read and print the message
    printf("Receiver: Read message: %s\n", shm);
    
    // Acknowledge by changing the message
    strcpy(shm, "ACK");
    printf("Receiver: Acknowledgment sent.\n");
    
    shmdt(shm);
    return 0;
}
