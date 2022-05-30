//Calculadora de notas de estudiantes, pidiendo el numero de notas al usuario.
//Diego Rincón C.I. 29.929.768

#include <stdio.h>

int main(){
	
	//Declaración de variables
	int cantidadNotas;
	int suma = 0;
	double resultado = 0;
	int *notas;
	
	//Pedir cantidad de notas al usuario
	printf("Ingrese la cantidad de notas del estudiante: ");
	scanf("%d", &cantidadNotas);
	
	//Creando un arreglo dinámico, donde notas apunta al inicio del arreglo.
	notas = new int[cantidadNotas];
	
	//Pidiendo las notas al usuario
	for(int i = 0; i < cantidadNotas; i++){
		printf("Ingrese la nota [%d]: ", i + 1);
		scanf("%d", &notas[i]);
		suma += notas[i];
	}
	
	//Mostrando las notas del usuario y su posicion en memoria, así como el promedio de las notas
	printf("\n\nMostrando las notas del estudiante:\n");
	for(int i = 0; i < cantidadNotas; i++){
		printf("Nota [%d]: %d\n", i + 1, notas[i]);
		printf("Posicion en memoria: %d\n\n", &notas[i]);
	}
	
	resultado = suma/cantidadNotas;
	printf("\nPromedio del estudiante: %lf", resultado);
	
	//Liberando la memoria asignada anteriormente
	delete[]notas;
	
	return 0;
}
