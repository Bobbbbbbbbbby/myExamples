#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = fork();
    if(pid != 0)
    {
        printf("(pid = %d)\n", pid);
        printf("This is parent, pid = %d\n", getpid());
        char *array[] = {"./fork", NULL};
        execv("./fork", array);
    }
    else
    {
        char *array[] = {"ls", "-l", NULL};
        execvp("ls", array);
        printf("(pid = %d)\n", pid);
        printf("This is child, pid = %d\n", getpid());
    }
    return 0;
}

/*
exec
+l = execl use list to pass parameters
+v = execv use array to pass parameters ** array means argv, the first element is name of the program
+x+p = use file name, I need full path if I donot use p
*/