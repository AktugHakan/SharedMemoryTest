#include <stdio.h>
#include "config.h"
#include "shm_lib/shmlib.h"

int main()
{
    ipc_data *shared_obj = connect_shared_memory(SHM_FILE_PATH, PROJ_ID);

    // Write begins
    (*shared_obj).locked = LOCKED; // prevent race conditions
    scanf("%s", (*shared_obj).message);
    // Write complete
    (*shared_obj).locked = UNLOCKED;

    disconnect_shared_memory();
    return 0;
}

