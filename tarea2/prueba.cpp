//Comparacion de dos arrays que retornan un array resultante

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *nros_1, *nros_2, *nros_3, cantidad, i;

	printf("Ingrese la cantidad de numeros a comparar: ");
	scanf("%d", &cantidad);
	
	nros_1 = (int *)malloc(cantidad * sizeof(int));
	nros_2 = (int *)malloc(cantidad * sizeof(int));
	nros_3 = (int *)malloc(cantidad * sizeof(int));
	
	printf("\n---ARREGLO NRO1---\n");
	for(i=0; i < cantidad; i++){
		printf("Ingrese el numero [%d]: ", i+1);
		scanf("%d", &nros_1[i]);
	}
	
	printf("\n---ARREGLO NRO2---\n");
	for(i=0; i < cantidad; i++){
		printf("Ingrese el numero [%d]: ", i+1);
		scanf("%d", &nros_2[i]);
	}
	
	for(i=0; i < cantidad; i++){
		if(nros_1[i] == nros_2[i]) {
			nros_3[i] = 1;
		} else {
			nros_3[i] = 0;
		}
	}
	
	printf("\n---ARREGLO RESULTANTE---\n");
	for(i=0; i < cantidad; i++){
		printf("Elemento [%d]: %d\n", i+1, nros_3[i]);
	}
	
	return 0;
}



