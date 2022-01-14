#include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    pid = fork();

    if(pid == 0){
        printf("The value of pid is: %d \n", pid);
        execlp("/bin/ls", "ls", NULL);
    }else if(pid > 0){
        wait(NULL);
        printf("The value of pid is: %d \n", pid);
        printf("Child completed execution");
    }

    return 0;
}