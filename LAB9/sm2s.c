#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

typedef struct {
    char server_msg[256];
    char client_msg[256];
    int flag_server; // set to 1 when server sends a message
    int flag_client; // set to 1 when client sends a reply
} shared_data;

#define SHM_SIZE sizeof(shared_data)

int main(){
    key_t key = 5678; // shared key
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if(shmid < 0){
        perror("shmget");
        exit(1);
    }
    shared_data *data = (shared_data *) shmat(shmid, NULL, 0);
    if(data == (void *) -1){
        perror("shmat");
        exit(1);
    }
    // Initialize flags
    data->flag_server = 0;
    data->flag_client = 0;
    
    // Server sends message
    strcpy(data->server_msg, "Hello from Server");
    data->flag_server = 1;
    printf("Server: Message sent: %s\n", data->server_msg);
    
    // Wait for client reply
    while(data->flag_client == 0){
        sleep(1);
    }
    printf("Server: Received reply: %s\n", data->client_msg);
    
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
