#include "lista.h"
#include <stdlib.h>

Lista* cria_lista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if (!lista) return NULL;
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

void insere_lista(Lista* lista, Cliente* cliente) {
    if (!lista || !cliente) return;
    Nodo* nodo = cria_nodo(cliente);
    nodo->prox = lista->inicio;
    lista->inicio = nodo;
    lista->tamanho++;
}

void libera_lista(Lista* lista) {
    if (!lista) return;
    Nodo* atual = lista->inicio;
    while (atual) {
        Nodo* prox = atual->prox;
        libera_nodo(atual);
        atual = prox;
    }
    free(lista);
}

int get_quantidade(Lista* lista) {
    return lista ? lista->tamanho : 0;
}

Nodo* get_inicio(Lista* lista) {
    return lista ? lista->inicio : NULL;
}
