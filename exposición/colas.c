#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct persona {
    char nombre[10];
    long int cedula;
    int edad;
} Persona;

typedef struct nodo {
    Persona *dato;
    struct nodo *sig;
} Nodo;

typedef struct cola {
    Nodo *primero;
    Nodo *ultimo;
    int total;
} Cola;

//--------------- PROTOTIPOS ---------------
Persona *crearPersona(long int cedula, int edad, char nombre[10]);
Nodo *crearNodo(Persona *persona);
Cola *crearCola();

void eliminarNodo(Nodo *nodo);
void liberar(Cola *cola);

int estaVacia(Cola *cola);

//------------ MÉTODOS DE LA COLA ------------
void insertar(Cola *cola, Persona *persona);
void eliminar(Cola *cola);
void promedio(Cola *cola);
void imprimir(Cola *cola);


int main() {

    Cola *cola = crearCola();

    Persona *p1, *p2, *p3, *p4, *p5;

    p1 = crearPersona(29929768, 19, "Diego");
    p2 = crearPersona(26167955, 25, "Pedro");
    p3 = crearPersona(11879923, 47, "Lorenzo");
    p4 = crearPersona(9295123, 50, "Ana");
    p5 = crearPersona(29836922, 19, "Luisrome");

    insertar(cola, p1);
    insertar(cola, p2);
    printf("Se ingresaron 2 personas\n\n");

    imprimir(cola);
    promedio(cola);

    insertar(cola, p3);
    insertar(cola, p4);
    insertar(cola, p5);
    printf("Se ingresaron 3 personas\n\n");

    imprimir(cola);
    promedio(cola);

    eliminar(cola);
    printf("Se elimino una persona\n\n");

    imprimir(cola);
    promedio(cola);

    liberar(cola);

    return 0;
}

Persona *crearPersona (long int cedula, int edad, char nombre[10]) {
    
    Persona *aux = (Persona*)malloc(sizeof(Persona));

    strcpy(aux->nombre, nombre);
    aux->cedula = cedula;
    aux->edad = edad;

    return aux;
}

Cola *crearCola() {

    Cola *aux = (Cola*)malloc(sizeof(Cola));
    aux->primero = NULL;
    aux->ultimo = NULL;
    aux->total = 0;

    return aux;
}

Nodo *crearNodo(Persona *persona) {

    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = persona;
    aux->sig = NULL;

    return aux;
}

void eliminarNodo(Nodo *nodo) {

    nodo->dato = NULL;
    nodo->sig = NULL;
    free(nodo);
}

int estaVacia(Cola *cola) {

    if (cola->total == 0) {
        return 1;
    } 
    else {
        return 0;
    }
}

void insertar(Cola *cola, Persona *persona) {

    Nodo *nuevo = crearNodo(persona);

    if (estaVacia(cola)) {
        cola->primero = nuevo;
        cola->ultimo = nuevo;
    }
    else {
        cola->ultimo->sig = nuevo;
        cola->ultimo = nuevo;
    }

    cola->total++;
}

void eliminar(Cola *cola) {

	if(estaVacia(cola)) {
		printf("La cola se encuentra vacia. No se puede borrar nada.\n\n");
	}
	else {
		
		Nodo *borrar = cola->primero;

	    if (cola->primero == cola->ultimo) {
	        cola->primero = NULL;
	        cola->ultimo = NULL;
	    }
	    else {
	        cola->primero = cola->primero->sig;
	    }
	
	    eliminarNodo(borrar);
	
	    cola->total--;
	}    
}

void promedio(Cola *cola) {
	
	int suma = 0;
	int contador = 0;
	int promedio = 0;
	Nodo *recorrer = cola->primero;
	
	while(recorrer != NULL) {
		suma += recorrer->dato->edad;
		contador++;
		recorrer = recorrer->sig;
	}
	
	promedio = suma/contador;
	
	printf("Promedio de edad de las personas en la cola: %d anios\n\n", promedio);
}


void imprimir(Cola *cola) {

    if(!estaVacia(cola)) {

        int contador = 1;

        Nodo *recorrer = cola->primero;
        printf("LISTADO DE PERSONAS EN LA COLA\n\n");

        while (recorrer != NULL) {
            printf("========================\n");
            printf("      PERSONA N%d\n", contador);
            printf("------------------------\n");
            printf("Nombre: %s\n", recorrer->dato->nombre);
            printf("Cedula: %ld\n", recorrer->dato->cedula);
            printf("Edad: %d\n", recorrer->dato->edad);
            printf("========================\n\n");

            recorrer = recorrer->sig;
            contador++;
        }
    }
    else {
        printf("La cola esta vacia");
    }
   
}


void liberar(Cola *cola) {

    while (!estaVacia(cola)) {
        eliminar(cola);
    }
    free(cola);

    printf("Se ha eliminado la cola.\n\n");
}
