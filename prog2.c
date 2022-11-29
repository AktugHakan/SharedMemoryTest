#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdio.h>
#include "config.h"

int main()
{
    // Same steps when creating the shared memory
    key_t key = ftok("shared_mem", PROJ_ID);
    int shared_memory_id = shmget(key, 512, 0666 | IPC_CREAT);
    char *buff = (char*) shmat(shared_memory_id, NULL, 0);

    // Read data from shared memory
    printf("DATA: %s", buff);

    // Detach itself from shared memory (shared memory still exists after detach)
    shmdt(buff);

    // Remove the shared memory to prevent memory leaks
    shmctl(shared_memory_id, IPC_RMID, NULL);

    return 0;
}