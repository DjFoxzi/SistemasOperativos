#include <unistd.h>                                                            
#include <stdio.h>                                                             
#include <sys/types.h>
#include <sys/wait.h>                                                                               
int main(int argc, char** argv) {                                              
  pid_t pid;                                                                   
                                                                               
  pid = fork();                                                                
  if(pid==0){
    sleep(3);                                                                  
    printf("Soy el hijo y mi identificador es %d\n",getpid());                                                         
  } else {
   int status;
    wait(&status);                                                                     
    printf("Soy el padre y mi identificador es %d y el de mi hijo es %d\n",getpid(),pid);                                                          
  }                                                                            
}
