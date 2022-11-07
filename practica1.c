#include <stdio.h>
#include <stdlib.h>

#define NUM_FILAS 4
#define MAX_LINE 100
#define TAM_LINEA 8
#define LRAM 1024

typedef struct {
	unsigned char ETQ;
	unsigned char Data[TAM_LINEA];
} T_CACHE_LINE

void LimpiarCACHE(T_CACHE_LINE tbl[NUM_FILAS]);
void VolcarCACHE(T_CACHE_LINE *tbl);
void ParsearDireccion(unsigned int addr, int *ETQ, int*palabra, int *linea, int *bloque);
void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ,int linea, int bloque);

int globaltime = 0; //iniciamos la variable globaltime a 0 cada vez que se inicia el programa          variable global
int numfallos = 0; //iniciamos variable de numeor de fallos a 0 cadea vez que se inicie el programa    variable golabl

int main (int argc, char** argv){
	
	//Abrirmos los archivos necesarios para el programa de calculo de cache en modo lectura
	FILE *Simul_RAM;
	Simul_RAM = fopen(CONTENTS_RAM.bin, "r"); //mirar si se tiene que abrir en binario --preguntar--
	
	if(Simul_RAM == NULL){
		printf("Error, archivo no encontrado\n");  //condicion en la que si el archivo no se encuentra en el directorio acaba el programa con un error
		return -1;
	}
	
	FILE *dirs_memoria;
	dirs_memoria = fopen(accesos_memoria.txt, "r");
	
	if(dirs_memoria == NULL){
		printf("Error, archivo no encontrado\n");  //condicion en la que si el archivo no se encuentra en el directorio acaba el programa con un error
		return -1;
	}
	
	

	return 0;
}
