# What is a "shared memory"?
Shared memory is a IPC (Inter-Process Communication) method.
It creates a memory block that multiple processes can access simultaneously.

## Race Conditions
This may cause race conditions, to prevent race conditions we can declare some part of the shared memory as "lock". The write guarding depends on application.
