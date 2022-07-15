#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct cancion {
    char nombre[30];
    char artista[30];
    int duracion;
} Cancion;

typedef struct nodo {
    Cancion *dato;
    struct nodo *sig;
} Nodo;

typedef struct lista {
    Nodo *primero;
    int total;
} Lista;

//-------------- PROTOTIPOS --------------
Lista *crearLista();
Nodo *crearNodo(Cancion *cancion);
Cancion *crearCancion(char nombre[30], char artista[30], int duracion);

void eliminarNodo(Nodo *nodo);
void liberar(Lista *lista);

int estaVacia(Lista *lista);

//------------ METODOS DE LA LISTA ------------
void insertarInicio(Lista *lista, Cancion *cancion);
void insertarFinal(Lista *lista, Cancion *cancion);
void insertarDespues(int n, Lista *lista, Cancion *cancion);

void eliminarInicio(Lista *lista);
void eliminarFinal(Lista *lista);
void eliminarPos(int n, Lista *lista);

int verTotal(Lista *lista);
void imprimir(Lista *lista);

int main() {

	//Se crea la lista a usar en el programa
    Lista *lista = crearLista();

	//Secrean las canciones a usar en el programa
    Cancion *c1, *c2, *c3, *c4;

    c1 = crearCancion("Animal I Have Become", "Three Days Grace", 231);
    c2 = crearCancion("Rock Bottom", "Grandson", 219);
    c3 = crearCancion("Stockholm Syndrome", "Muse", 300);
    c4 = crearCancion("Clockwork", "Northlane", 238);

	//Insertando las canciones
    insertarInicio(lista, c1);
    insertarInicio(lista, c3);
    insertarInicio(lista, c4);
    insertarDespues(1, lista, c2);
    printf("Se agregaron 4 canciones\n\n\n");

	//Se imprime la lista
    imprimir(lista);
    verTotal(lista);

    insertarFinal(lista, c4);
    printf("Se agrego una cancion al final de la lista\n\n\n");

    imprimir(lista);
    verTotal(lista);

	//Eliminando canciones
    eliminarInicio(lista);
    eliminarFinal(lista);
    printf("Se eliminaron la primera y ultima cancion\n\n\n");

    imprimir(lista);
    verTotal(lista);

    eliminarPos(1, lista);
    printf("Se elimino la cancion del medio\n\n\n");

    imprimir(lista);
    verTotal(lista);


    return 0;
}

Cancion *crearCancion(char nombre[30], char artista[30], int duracion) {

    Cancion *aux = (Cancion*)malloc(sizeof(Cancion));

    strcpy(aux->nombre, nombre);
    strcpy(aux->artista, artista);
    aux->duracion = duracion;

    return aux;
}


Lista *crearLista() {

    Lista *aux = (Lista*)malloc(sizeof(Lista));
    aux->primero = NULL;
    aux->total = 0;

    return aux;
}


Nodo *crearNodo(Cancion *cancion) {

    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = cancion;
    aux->sig = NULL;

    return aux;
}

int estaVacia(Lista *lista) {
    if(lista->total == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void eliminarNodo(Nodo *nodo) {

    nodo->dato = NULL;
    free(nodo);
}

void insertarInicio(Lista *lista, Cancion *cancion) {

    Nodo *nuevo = crearNodo(cancion);

    nuevo->sig = lista->primero;
    lista->primero = nuevo;

    lista->total++;
}

void insertarFinal(Lista *lista, Cancion *cancion) {

    Nodo *nuevo = crearNodo(cancion);

    if(estaVacia(lista)) {
        lista->primero = nuevo;
    } 
    else {
        
        Nodo *aux = lista->primero;

        while(aux->sig != NULL) {
            aux = aux->sig;
        }

        aux->sig = nuevo;
    }
   
    lista->total++;
}

void insertarDespues(int n, Lista *lista, Cancion *cancion) {

    Nodo *nuevo = crearNodo(cancion);

    if(estaVacia(lista)){
        lista->primero = nuevo;
    }
    else {
        int pos = 0;
        Nodo *aux = lista->primero;

        while(pos < n && aux->sig != NULL) {
            aux = aux->sig;
            pos++;
        }

        nuevo->sig = aux->sig;
        aux->sig = nuevo;

        lista->total++;
    }
}

int verTotal(Lista *lista) {
    printf("\nEl total de canciones es: %d\n\n", lista->total);
}

void eliminarInicio(Lista *lista) {

    if(!estaVacia(lista)) {

        Nodo *borrar = lista->primero;
        lista->primero = lista->primero->sig;

        eliminarNodo(borrar);

        lista->total--;
    }
    else {
        printf("Se intento hacer una eliminacion con la lista vacia\n\n");
    }   
}

void eliminarFinal(Lista *lista) {

    if(!estaVacia(lista)) {

        if(lista->primero->sig != NULL) {

            Nodo *aux = lista->primero;
        
            while(aux->sig->sig != NULL) {
                aux = aux->sig;
            }

            Nodo *borrar = aux->sig;
            aux->sig = NULL;

            eliminarNodo(borrar);

            lista->total--;
        }
        else {

            Nodo *borrar = lista->primero;
            lista->primero = NULL;

            eliminarNodo(borrar);

            lista->total--;
        }

    }
    else {
        printf("Se intento hacer una eliminacion con la lista vacia\n\n");
    }   
}

void eliminarPos(int n, Lista *lista) {

    if(!estaVacia(lista)) {

        if(n == 0) {

            Nodo *borrar = lista->primero;
            lista->primero = lista->primero->sig;

            eliminarNodo(borrar);

            lista->total--;
        }
        else if(n < lista->total) {

            int pos = 0;
            Nodo *aux = lista->primero;

            while(pos < (n - 1)) {
                aux = aux->sig;
                pos++;
            }

            Nodo *borrar = aux->sig;
            aux->sig = borrar->sig;

            eliminarNodo(borrar);

            lista->total--;
        }
        else {
            printf("La posicion ingresada no existe\n\n");
        }
    }
    else {
        printf("Se intento hacer una eliminacion con la lista vacia\n\n");
    }  
}

void liberar(Lista *lista) {

    while(!estaVacia(lista)) {

        Nodo *borrar = lista->primero;
        Nodo *aux = lista->primero;

        if(aux->sig == NULL) {
            aux = NULL;
        } else {
            aux = aux->sig;
        }

        eliminarNodo(borrar);

        lista->total--;
    }
    free(lista);
}

void imprimir(Lista *lista) {

    if(!estaVacia(lista)) {

        int contador = 0;
        Nodo *recorrer = lista->primero;
        printf("LISTADO DE CANCIONES EN LA LISTA\n\n");

        while(recorrer != NULL) {
            printf("===================================\n");
            printf("            CANCION N%d\n", contador);
            printf("-----------------------------------\n");
            printf("Nombre: %s\n", recorrer->dato->nombre);
            printf("Artista: %s\n", recorrer->dato->artista);
            printf("Duracion: %d s\n", recorrer->dato->duracion);
            printf("===================================\n");

            recorrer = recorrer->sig;
            contador++;
        }
    }
    else {
        printf("La lista esta vacia\n\n");
    }
}
