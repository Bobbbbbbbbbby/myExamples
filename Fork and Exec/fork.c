#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = fork();
    if(pid == 0)
    {
        printf("This is child, pid = %d\n", pid);
        // fork return 0 to the int pid of child
    }
    else
    {
        printf("This is parent, pid = %d\n", pid);
        // fork return pid of child to int pid of parent
    }
    return 0;
}