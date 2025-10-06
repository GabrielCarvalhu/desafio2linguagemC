#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdbool.h>

#define TAM_NOME 40
#define TAM_BAIRRO 40

typedef struct Cliente {
    char nome[TAM_NOME];
    char bairro[TAM_BAIRRO];
    int pessoas;
    bool crianca_menor_5;
    double renda;
} Cliente;

Cliente* cria_cliente(const char* nome, const char* bairro, int pessoas, bool crianca_menor_5, double renda);
void libera_cliente(Cliente* cliente);

// Getters
const char* get_nome(Cliente* cliente);
const char* get_bairro(Cliente* cliente);
int get_pessoas(Cliente* cliente);
bool get_criancas(Cliente* cliente);
double get_renda(Cliente* cliente);

#endif // CLIENTE_H
