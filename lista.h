#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

typedef struct Lista {
    Nodo* inicio;
    int tamanho;
} Lista;

Lista* cria_lista();
void insere_lista(Lista* lista, Cliente* cliente);
void libera_lista(Lista* lista);

// Getters
int get_quantidade(Lista* lista);
Nodo* get_inicio(Lista* lista);

#endif // LISTA_H
