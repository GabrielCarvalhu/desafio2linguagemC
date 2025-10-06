#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "lista.h"

#define TAM_HASH 101

// Critérios de busca
#define CRIT_NOME 1
#define CRIT_BAIRRO 2
#define CRIT_PESSOAS 3
#define CRIT_CRIANCA 4
#define CRIT_RENDA 5

typedef struct Estrutura {
    Lista* hash_nome[TAM_HASH];
    Lista* hash_bairro[TAM_HASH];
    Lista* hash_pessoas[6]; // 1 a 5+ (índice 1 a 5)
    Lista* hash_crianca[2]; // 0: não, 1: sim
    Lista* hash_renda[4];   // 0: <=2000, 1: 2000-3000, 2: 3000.01-5000, 3: >5000
} Estrutura;

Estrutura* cria_estrutura();
void insere_cliente(Estrutura* estrutura, int criterio, Cliente* cliente);
Lista* recupera_cliente(Estrutura* estrutura, int criterio, int complemento, char* busca);
void libera_estrutura(Estrutura* estrutura);

#endif // ESTRUTURA_H
