#include "estrutura.h"
#include <stdlib.h>
#include <string.h>

// Funções de hash simples para nome e bairro
static int hash_string(const char* str) {
    unsigned int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = hash * 31 + str[i];
    }
    return hash % TAM_HASH;
}

static int hash_pessoas(int pessoas) {
    if (pessoas >= 5) return 5;
    if (pessoas < 1) return 1;
    return pessoas;
}

static int hash_crianca(bool crianca) {
    return crianca ? 1 : 0;
}

static int hash_renda(double renda) {
    if (renda <= 2000.0) return 0;
    if (renda <= 3000.0) return 1;
    if (renda <= 5000.0) return 2;
    return 3;
}

Estrutura* cria_estrutura() {
    Estrutura* estrutura = (Estrutura*)malloc(sizeof(Estrutura));
    if (!estrutura) return NULL;
    for (int i = 0; i < TAM_HASH; i++) {
        estrutura->hash_nome[i] = cria_lista();
        estrutura->hash_bairro[i] = cria_lista();
    }
    for (int i = 1; i <= 5; i++) {
        estrutura->hash_pessoas[i] = cria_lista();
    }
    estrutura->hash_pessoas[0] = NULL;
    estrutura->hash_crianca[0] = cria_lista();
    estrutura->hash_crianca[1] = cria_lista();
    for (int i = 0; i < 4; i++) {
        estrutura->hash_renda[i] = cria_lista();
    }
    return estrutura;
}

void insere_cliente(Estrutura* estrutura, int criterio, Cliente* cliente) {
    if (!estrutura || !cliente) return;
    switch (criterio) {
        case CRIT_NOME: {
            int h_nome = hash_string(cliente->nome);
            insere_lista(estrutura->hash_nome[h_nome], cliente);
            break;
        }
        case CRIT_BAIRRO: {
            int h_bairro = hash_string(cliente->bairro);
            insere_lista(estrutura->hash_bairro[h_bairro], cliente);
            break;
        }
        case CRIT_PESSOAS: {
            int h_pessoas = hash_pessoas(cliente->pessoas);
            insere_lista(estrutura->hash_pessoas[h_pessoas], cliente);
            break;
        }
        case CRIT_CRIANCA: {
            int h_crianca = hash_crianca(cliente->crianca_menor_5);
            insere_lista(estrutura->hash_crianca[h_crianca], cliente);
            break;
        }
        case CRIT_RENDA: {
            int h_renda = hash_renda(cliente->renda);
            insere_lista(estrutura->hash_renda[h_renda], cliente);
            break;
        }
        default:
            break;
    }
}

Lista* recupera_cliente(Estrutura* estrutura, int criterio, int complemento, char* busca) {
    if (!estrutura) return NULL;
    switch (criterio) {
        case CRIT_NOME:
            if (!busca) return NULL;
            return estrutura->hash_nome[hash_string(busca)];
        case CRIT_BAIRRO:
            if (!busca) return NULL;
            return estrutura->hash_bairro[hash_string(busca)];
        case CRIT_PESSOAS:
            if (complemento < 1) complemento = 1;
            if (complemento > 5) complemento = 5;
            return estrutura->hash_pessoas[complemento];
        case CRIT_CRIANCA:
            if (complemento != 0 && complemento != 1) return NULL;
            return estrutura->hash_crianca[complemento];
        case CRIT_RENDA:
            if (complemento < 0 || complemento > 3) return NULL;
            return estrutura->hash_renda[complemento];
        default:
            return NULL;
    }
}

void libera_estrutura(Estrutura* estrutura) {
    if (!estrutura) return;
    for (int i = 0; i < TAM_HASH; i++) {
        libera_lista(estrutura->hash_nome[i]);
        libera_lista(estrutura->hash_bairro[i]);
    }
    for (int i = 1; i <= 5; i++) {
        libera_lista(estrutura->hash_pessoas[i]);
    }
    for (int i = 0; i < 2; i++) {
        libera_lista(estrutura->hash_crianca[i]);
    }
    for (int i = 0; i < 4; i++) {
        libera_lista(estrutura->hash_renda[i]);
    }
    free(estrutura);
}
