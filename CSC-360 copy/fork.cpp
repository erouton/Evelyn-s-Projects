#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
  int status;
  pid_t pid;

  pid = fork();
  
  if(pid < 0){
    fprintf(stderr, "Fork Failed!");
    return 1;
  }else if(pid == 0){
    sleep(1);
    execlp("/bin/ls", "ls", NULL);
    
  }else{
    wait(NULL);
    printf("Child Complete!%d,%d\n",pid,status);
  }
  return 0;
}



