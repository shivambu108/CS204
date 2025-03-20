#include <stdio.h>      // For printf(), perror()
#include <stdlib.h>     // For exit()
#include <string.h>     // For strcpy()
#include <sys/ipc.h>    // For IPC keys and permissions
#include <sys/shm.h>    // For shared memory functions
#include <unistd.h>     // For sleep()

// Define a structure to hold two messages and synchronization flags.
typedef struct {
    char server_msg[256]; // Buffer for the server's message
    char client_msg[256]; // Buffer for the client's message
    int flag_server;      // Flag set to 1 when server sends a message
    int flag_client;      // Flag set to 1 when client sends a reply
} shared_data;

#define SHM_SIZE sizeof(shared_data)  // Size of our shared memory segment

int main(){
    key_t key = 5678; // Unique key for the shared memory segment
    // Create the shared memory segment with required permissions.
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if(shmid < 0){
        perror("shmget");
        exit(1);
    }
    // Attach the shared memory segment to the process.
    shared_data *data = (shared_data *) shmat(shmid, NULL, 0);
    if(data == (shared_data *) -1){
        perror("shmat");
        exit(1);
    }
    // Initialize synchronization flags.
    data->flag_server = 0;
    data->flag_client = 0;
    
    // Write the server message and set its flag.
    strcpy(data->server_msg, "Hello from Server");
    data->flag_server = 1;
    printf("Server: Message sent: %s\n", data->server_msg);
    
    // Wait until the client sets its flag indicating a reply.
    while(data->flag_client == 0){
        sleep(1);
    }
    printf("Server: Received reply: %s\n", data->client_msg);
    
    // Detach the shared memory.
    shmdt(data);
    // Remove the shared memory segment.
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
