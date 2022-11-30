
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include "shmlib.h"

int shared_mem_id = NULL;
ipc_data* shared_mem_addr = NULL;

ipc_data *connect_shared_memory(const char *shm_file_path, const int proj_id)
{
    // Get a unique key from project id and path name
    key_t key = ftok(shm_file_path, proj_id);

    /* Allocate SystemV shared memory segment
     * IPC_CREAT is used to create a new memory segment if not exists.
     * IPC_EXCL is used to ensure that the process creates the shared mem. If it already exists, program fails
     */
    shared_mem_id = shmget(key, sizeof(ipc_data), 0666 | IPC_CREAT);

    // Attach itself to shared memory
    shared_mem_addr = (ipc_data *)shmat(shared_mem_id, NULL, 0);

    return shared_mem_addr;
}

void disconnect_shared_memory()
{
    shmdt(shared_mem_addr);
}

void remove_shared_memory()
{
    shmctl(shared_mem_id, IPC_RMID, NULL);
}