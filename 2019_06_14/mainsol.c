#include "solucion.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char** argv) {
 pid_t pid;

 pid = fork();
 int x = 20;
  if(pid==0){
 printf("  soy el hijo\n  calculo fibonacci de %d\n",x);
 x = fibonacci(x);
 printf("  guardo el valor calculado %d en archivo 'fibonacci'\n",x);
 guardarEntero("fibonacci",x);
 }
 else{
 printf("soy el padre\nEspero que termine mi hijo\n");
 wait(NULL);
  printf("leo el valor que calculo mi hijo del archivo 'fibonacci'\n ");
  x = leerEntero("fibonacci") * 100;
  printf("multiplico por 100 e imprimo por pantalla %d\n",x);
}
  return 0;
}
