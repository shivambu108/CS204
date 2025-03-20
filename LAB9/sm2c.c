#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

typedef struct {
    char server_msg[256];
    char client_msg[256];
    int flag_server;
    int flag_client;
} shared_data;

#define SHM_SIZE sizeof(shared_data)

int main(){
    key_t key = 5678; // same key as server
    int shmid = shmget(key, SHM_SIZE, 0666);
    if(shmid < 0){
        perror("shmget");
        exit(1);
    }
    shared_data *data = (shared_data *) shmat(shmid, NULL, 0);
    if(data == (void *) -1){
        perror("shmat");
        exit(1);
    }
    // Wait until server sends its message
    while(data->flag_server == 0){
        sleep(1);
    }
    printf("Client: Received message: %s\n", data->server_msg);
    
    // Send reply
    strcpy(data->client_msg, "Hello from Client");
    data->flag_client = 1;
    printf("Client: Reply sent: %s\n", data->client_msg);
    
    shmdt(data);
    return 0;
}
