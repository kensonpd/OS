#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
    pid_t pid;
    pid=vfork();
    if(pid==-1)
    {
        perror("vfork");
        return 1;
    }
    else if(pid==0)
    {
        printf("Child process:Hello,I'm the Child\n");
        printf("Child process:My PID is %d\n",getpid());
        printf("Child process:My Parent PID is %d\n",getpid());
        exit(0);
    }
    else
    {
        printf("Parent  process:Hello,I'm the parent!\n");
        printf("Parent process:My PID is %d\n",getpid());
        printf("Parent process:My Child's PID is %d\n",pid); 
               
    }
    int status;
    waitpid(pid,&status,0);
    if(WIFEXITED(status))
    {
        printf("parent process:Child process terminated normally\n");
    }
    else
    {
        printf("Parent process: Child process terminated abnormally\n");
    }
}