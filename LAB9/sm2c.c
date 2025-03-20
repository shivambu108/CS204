#include <stdio.h>      // For printf(), perror()
#include <stdlib.h>     // For exit()
#include <string.h>     // For strcpy()
#include <sys/ipc.h>    // For IPC keys
#include <sys/shm.h>    // For shared memory functions
#include <unistd.h>     // For sleep()

// Same structure definition as in the server.
typedef struct {
    char server_msg[256]; // Buffer for the server's message
    char client_msg[256]; // Buffer for the client's message
    int flag_server;      // Flag set when server sends a message
    int flag_client;      // Flag set when client sends a reply
} shared_data;

#define SHM_SIZE sizeof(shared_data)  // Size of the shared memory segment

int main(){
    key_t key = 5678; // Use the same key as the server to access the segment
    // Locate the shared memory segment.
    int shmid = shmget(key, SHM_SIZE, 0666);
    if(shmid < 0){
        perror("shmget");
        exit(1);
    }
    // Attach the shared memory segment.
    shared_data *data = (shared_data *) shmat(shmid, NULL, 0);
    if(data == (shared_data *) -1){
        perror("shmat");
        exit(1);
    }
    // Wait until the server sends its message.
    while(data->flag_server == 0){
        sleep(1);
    }
    // Print the server's message.
    printf("Client: Received message: %s\n", data->server_msg);
    
    // Write a reply message and set the client flag.
    strcpy(data->client_msg, "Hello from Client");
    data->flag_client = 1;
    printf("Client: Reply sent: %s\n", data->client_msg);
    
    // Detach the shared memory.
    shmdt(data);
    return 0;
}
