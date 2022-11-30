#include <stdio.h>
#include "config.h"
#include "shm_lib/shmlib.h"

// for sleep function
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int main()
{
    ipc_data* shared_memory = connect_shared_memory(SHM_FILE_PATH, PROJ_ID);
    
    printf("Connected and waiting for other program to write...\n");

    while((*shared_memory).locked)
    {
        sleep(1);
        printf("Still waiting...\n");
    }

    printf("Message is: %s\n", (*shared_memory).message);

    return 0;
}