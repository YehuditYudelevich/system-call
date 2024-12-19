# Explanation of the project in the word file
 
 # 1 Using fwrite() (User Mode, High-Level)
What it is: The simplest way to write to a file using C/C++ via the libc library.
How it works: Calls fwrite(), which interacts with system calls like write() in the background.

# 2 Using write() (User Mode, Low-Level)

What it is: A lower-level way to write to files, directly using system calls via unistd.h.
How it works: Calls write(), which transitions from User Mode to Kernel Mode using syscall to ask the kernel to write the data.

# 3 Using syscall() (Direct System Call)

What it is: Instead of using write(), you call the kernel directly using the syscall() function, bypassing libc entirely.
How it works: The syscall() function triggers the kernel to handle the system call directly.

# 4 Using Assembly (Direct Call to the Kernel)
What it is: The lowest-level way to perform system calls, bypassing C functions entirely.
How it works: Uses the syscall instruction (x86-64) to transition from User Mode to Kernel Mode.
# 5 Using vfs_write() (Kernel Space)

What it is: Write to a file inside the kernel as part of a Kernel Module or Driver.
How it works: The vfs_write() function writes directly to the file system but requires set_fs() to change file system context (this method is now deprecated).
