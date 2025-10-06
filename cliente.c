#include "cliente.h"
#include <stdlib.h>
#include <string.h>

Cliente* cria_cliente(const char* nome, const char* bairro, int pessoas, bool crianca_menor_5, double renda) {
    Cliente* cliente = (Cliente*)malloc(sizeof(Cliente));
    if (!cliente) return NULL;
    strncpy(cliente->nome, nome, TAM_NOME);
    cliente->nome[TAM_NOME-1] = '\0';
    strncpy(cliente->bairro, bairro, TAM_BAIRRO);
    cliente->bairro[TAM_BAIRRO-1] = '\0';
    cliente->pessoas = pessoas;
    cliente->crianca_menor_5 = crianca_menor_5;
    cliente->renda = renda;
    return cliente;
}

void libera_cliente(Cliente* cliente) {
    if (cliente) free(cliente);
}

const char* get_nome(Cliente* cliente) {
    return cliente ? cliente->nome : NULL;
}

const char* get_bairro(Cliente* cliente) {
    return cliente ? cliente->bairro : NULL;
}

int get_pessoas(Cliente* cliente) {
    return cliente ? cliente->pessoas : 0;
}

bool get_criancas(Cliente* cliente) {
    return cliente ? cliente->crianca_menor_5 : false;
}

double get_renda(Cliente* cliente) {
    return cliente ? cliente->renda : 0.0;
}
