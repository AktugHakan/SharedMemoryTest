#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#include "config.h"

#define MESSAGE "Hello, world!\n"

int main()
{
    // Get a unique key from project id and path name
    key_t key = ftok("shared_mem", PROJ_ID);

    // Allocate SystemV shared memory segment
    // IPC_CREAT is used to create a new memory segment
    int shared_memory_id = shmget(key, 512, 0666 | IPC_CREAT);

    // Attach itself to shared memory
    char *str = (char*) shmat(shared_memory_id, NULL, 0);

    // Write to shared memory
    strcpy(str, MESSAGE);

    // Wait for key press
    scanf("%*c");

    // Detach itself from shared memory (shared memory still exists after detach)
    shmdt(str);

    return 0;
}