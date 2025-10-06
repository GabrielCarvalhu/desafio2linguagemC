#include "nodo.h"
#include <stdlib.h>

Nodo* cria_nodo(Cliente* cliente) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nodo) return NULL;
    nodo->cliente = cliente;
    nodo->prox = NULL;
    return nodo;
}

void libera_nodo(Nodo* nodo) {
    if (nodo) {
        // Não libera o cliente aqui, pois ele pode estar em várias listas
        free(nodo);
    }
}

Cliente* get_data(Nodo* nodo) {
    return nodo ? nodo->cliente : NULL;
}

Nodo* get_next(Nodo* nodo) {
    return nodo ? nodo->prox : NULL;
}
