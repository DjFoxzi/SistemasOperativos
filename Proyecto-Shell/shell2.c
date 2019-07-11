#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#define argumentos 15
#define caracteres 200

char comando[caracteres];
char *args[argumentos];
char PWD[caracteres];
char shell[caracteres];
char PATH[caracteres];
char home[caracteres];
FILE *bath;
char instruccion[caracteres];

void separaArgs(void){
  int i;
  for(i=0;i<(argumentos-1);i++) args[i]=NULL; /*Borrar argumento previo que pudiera existir*/
  strtok(comando," "), i=0; /*separar palabras individuales usando tokens (espacio vacio)*/
  args[i]=comando; /*El 1er argumento sera comando por un requerimiento de execvp*/
  while((args[++i]=strtok(NULL," "))!=NULL && i<(argumentos-2));
}

int main(int argc, char** argv){
	getcwd(PWD,caracteres);
	strcpy(PATH,getenv("PATH"));
	strcpy(home,getenv("HOME"));
	strcpy(shell,PWD);
	int correr = 1;
	int estado = 0;
	int cambio = 0;
	printf("Iniciando mini-shell\n");
    while(correr == 1){
	printf(" %s>",PWD);
	strcpy(comando, "");
	__fpurge(stdin);
	if(estado == 0){
	scanf("%[^\n]s",comando);
	}else{
    //fscanf(bath, "%s" ,instruccion);
	
	strcpy(comando, strtok(instruccion,"\n"));
    //strcpy(comando,instruccion);
 //   printf("%s/n",instruccion);
    printf("%s\n",comando);
	strcpy(comando,instruccion);
	fgets(instruccion,caracteres,bath);
	if(feof(bath) == 1){
	fclose(bath);
	cambio = 1;
    }
	}


    if(strlen(comando)>0){
	separaArgs();
    	if(estado==1){
	if (args[1]==0){
	strcat(comando," ");
	char aux[caracteres]="";
	printf("ingrese los <arguments> necesarios para que el comando %s pueda continuar\nSi no es necesario solo presione enter\n",comando);
	//__fpurge(stdin);
	scanf("%[^\n]s",aux);
	if(strlen(aux)>0){
	strcat(comando,aux);
	}
	separaArgs();
	}
	}

	if(strcmp(comando,"quit")==0){
	printf("Adios\n");
	correr = 0;
	}
		
	else if(strcmp(comando,"pause")==0){
	__fpurge(stdin);
	char tecla;
	char mensaje[]= "presiona enter para continuar\n";
	printf("%s",mensaje);
	while(tecla != '\n'){
		tecla= getchar();

	}
	}

	else if(strcmp(comando,"environ")==0){
	printf("%s\n",shell);
	}

	else if(strcmp(comando,"myshell")==0){
	if(args[1]==0){
	printf("debe tener argumentos\n");
	}
	else if(strcmp(args[1],"bathfile")==0 && args[2]==0){
	

	bath = fopen("bathfile","r");

	if(bath == NULL){
	printf("El archivo <bathfile> no exite\n");
	}else{
 
	estado = 1;
	fgets(instruccion,caracteres,bath);
	
	}


	}else{
	printf("Solo debe ir acompañado por el argumento bathfile\n");
	}
	}

	else if(strcmp(comando,"pwd")==0){
	printf("%s\n",PWD);
	}

	else if(strcmp(comando,"echo")==0){
	for(int i=1;i<argumentos-1;i++){
	if(args[i]==0) {
	break;
	}
	printf("%s",args[i]);
	printf(" ");
	}
	printf("\n");
	}
	else if(strcmp(comando,"cd")==0){
	if(chdir(args[1])==0){
	getcwd(PWD,caracteres);
	}else{
	printf("Error al cambiar de directorio\n");
	}

	}
	else if(strcmp(comando,"clr")==0){
	system("clear");
	}

	else if(strcmp(comando,"help")==0){
	printf("\n        Bienvenido a la ayuda\n \n " );
        printf("cd: Cambia el directorio predeterminado actual a <directorio> \n (Si el argumento <directorio> no esta presente, informa el directorio actual.) \n \n ");
        printf("clr: Limpia de texto tu pantalla \n \n ");
        printf("dir <directorio>: Lista los contenidos del directorio <directorio> \n \n ");
        printf("environ: lista todas las cadenas del entorno \n \n ");
        printf("echo: <comentario> Imprime <comentario> en la pantalla, seguido de un salto de linea\n \n ");
        printf("pause: Pausa la operacion de el shell hasta que 'Enter' es presionado.\n \n ");
        printf("quit: Cierra el shell.\n \n ");
        

	}

	else if(strcmp(comando,"dir")==0){
	int contador;
	struct dirent **directorios = NULL;
	if(args[1]==0 || strcmp(args[1],"")==0){
	contador=scandir(PWD, &directorios, NULL, NULL);
	}else{
	contador=scandir(args[1],&directorios, NULL, NULL);
	}
	if(contador== -1){
	printf("Error al listar directorio, el directorio no existe\n");
	}
	else{
	for(int i = 0;i<contador;i++){
	printf("%s ",directorios[i]->d_name);
	if (i % 3 == 0){
	printf("\n");
	}
	}
	printf("\n");
	}
}
	else{ 
  	int pid=0;
  	int status;
  	pid=fork(); 
  	if(pid<0) printf("Error no se pudo crear  hijo");
  	if (pid==0){
   	 status=execvp(comando,args); 
    	if(status){
      	printf("Error %s no se pudo ejecutar\n",comando);
      	exit(1); 
    		}
  	}
  	else
    	wait(NULL); 
	}


    }else{printf("no se ingreso ningun dato\n");}
	if(cambio==1){
	cambio = 0;
	estado= 0;
	}
    }
}