#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FILAS 8
#define MAX_LINE 100
#define TAM_LINEA 16
#define LRAM 4096

typedef struct {
	unsigned char ETQ;
	unsigned char Data[TAM_LINEA];
} T_CACHE_LINE;

void LimpiarCACHE(T_CACHE_LINE tbl[NUM_FILAS]);

//void VolcarCACHE(T_CACHE_LINE *tbl);
//void ParsearDireccion(unsigned int addr, int *ETQ, int*palabra, int *linea, int *bloque);
//void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ,int linea, int bloque);

int globaltime = 0; //iniciamos la variable globaltime a 0 cada vez que se inicia el programa          variable global
int numfallos = 0; //iniciamos variable de numeor de fallos a 0 cadea vez que se inicie el programa    variable golabl

int main (int argc, char** argv){
	
	//inicializar array de tipo T_CACHE_LINE 
	T_CACHE_LINE memoria[NUM_FILAS];
	LimpiarCACHE(memoria);
	
	//inicializar array de Simul_RAM
	//char Simul_RAM[LRAM];
	char Simul_RAM[LRAM];
	
	//Abrirmos los archivos necesarios para el programa de calculo de cache en modo lectura
	FILE *CONTENTS_RAM;
	CONTENTS_RAM = fopen("CONTENTS_RAM.bin", "r"); //mirar si se tiene que abrir en binario --preguntar--
	
	if(CONTENTS_RAM == NULL){
		printf("Error, archivo CONTENTS_RAM.bin no encontrado\n");  //condicion en la que si el archivo no se encuentra en el directorio acaba el programa con un error
		return -1;
	}else{	//guardar contenido de CONTENTS_RAM en Simul_RAM
				
		int contAux=0;			
		while(feof(CONTENTS_RAM) == 0)  //pasa al string Simul_Ram el contenido del archivo CONTENTS_RAM
		{
			Simul_RAM[contAux]=getc(CONTENTS_RAM);		
			contAux++;
		}		

		//printf("%s", Simul_RAM);			   //Prueba viendo por pantalla de que se guarda correctamente
			
	}
	
	
	FILE *dirs_memoria;
	dirs_memoria = fopen("accesos_memoria.txt", "r");   //Abre en binario numeros en hexadecimal
	
	if(dirs_memoria == NULL){
		printf("Error, archivo accesos_memoria.txt no encontrado\n");  //condicion en la que si el archivo no se encuentra en el directorio acaba el programa con un error
		return -1;
	}else{
		char aux_leer[3];

		while(feof(dirs_memoria)==0){
			fgets(aux_leer, 3, dirs_memoria);  //saca una direccion de memoria y la guarda en la variable aux_leer		
			printf("%s", aux_leer);	
			
			
		}
		
	}
	
	//cerrar los archivos
	fclose(CONTENTS_RAM);
	fclose(dirs_memoria);

	return 0;
}

void LimpiarCACHE(T_CACHE_LINE tbl[NUM_FILAS]){
	for(int i=0; i<NUM_FILAS; i++){
		tbl->ETQ=0xFF;
		for(int j=0; j<TAM_LINEA; j++){
			tbl[i].Data[j]=(char)0x23;
		}
			
	}
	
	//imprimir todo
	for(int i=0; i<NUM_FILAS; i++){
		//printf("%c",tbl->ETQ);
		for(int j=0; j<TAM_LINEA; j++){
			printf("%x", tbl[i].Data[j]);
		}
		printf("\n");
			
	}
}
