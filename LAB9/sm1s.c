#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main(){
    key_t key = 1234; // shared key
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if(shmid < 0){
        perror("shmget");
        exit(1);
    }
    char *shm = (char *) shmat(shmid, NULL, 0);
    if(shm == (char *) -1){
        perror("shmat");
        exit(1);
    }
    // Write message to shared memory
    strcpy(shm, "Message from Sender");
    printf("Sender: Message written to shared memory.\n");
    
    // Wait for receiver to change the message (acknowledgment)
    while(strcmp(shm, "Message from Sender") == 0){
        sleep(1);
    }
    printf("Sender: Acknowledgment received. Exiting.\n");
    
    // Detach and deallocate shared memory
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
