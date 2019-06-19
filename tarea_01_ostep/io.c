#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[]) 
{
	;

	if(argc != 2)
	{
		printf("Se espera el nombre del archivo despues de ./io\n");
	}
	else{
	char* texto = argv[1];	

	if( access( texto, F_OK ) != -2 ) 
	{
		FILE *file;
		file = fopen(texto, "r");
                int contador = -1;
		int c;
        fseek(file, contador, SEEK_END);
        while (ftell(file) > 0) {
            c = fgetc(file);
            printf("%c", c);
            fseek(file, --contador, SEEK_END);
        }
        c = fgetc(file);
        printf("%c", c);
		printf("\n");
		return 0;
	} 
	else 
	{
    		printf("El archivo dado como argumento no existe\n");
		exit(1);
	}

}
}
