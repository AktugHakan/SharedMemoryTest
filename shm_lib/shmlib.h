#define LOCKED 1
#define UNLOCKED 0

typedef struct ipc_data
{
    char locked;
    char message[1023];
} ipc_data; // 1024 bytes of data

ipc_data *connect_shared_memory(const char *shm_file_path, const int proj_id);
void disconnect_shared_memory();
void remove_shared_memory();
