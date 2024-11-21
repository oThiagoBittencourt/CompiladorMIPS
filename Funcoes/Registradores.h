#include <stdio.h>
#include <string.h>

// Estrutura

struct registrador{
char nome[5];
int id, valor;
};

void inicializarRegistradores(struct registrador registradores[]) {
    const char *nomesRegMutavel[] = {
        "$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3",
        "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7",
        "$t8", "$t9", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5",
        "$s6", "$s7", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra",
        "pc", "hi", "lo"
    };

    for (int i = 0; i < 35; i++) {
        strcpy(registradores[i].nome, nomesRegMutavel[i]);
        registradores[i].id = i;
        registradores[i].valor = 0;
    }
}

// Controle dos Registradores

void getRegistradorID(struct registrador registradores[], int id) {
    return registradores[id].valor;
}

void setRegistradorID(struct registrador registradores[], int id, int valor) {
    registradores[id].valor = valor;
}

int getRegistradorNome(struct registrador registradores[], const char *nome) {
    for (int i = 0; i < 35; i++) {
        if (strcmp(registradores[i].nome, nome) == 0) {
            return registradores[i].valor;
        }
    }
    printf("Erro: Registrador com nome '%s' não encontrado.\n", nome);
    return -1;
}

void setRegistradorNome(struct registrador registradores[], const char *nome, int valor) {
    for (int i = 0; i < 35; i++) {
        if (strcmp(registradores[i].nome, nome) == 0) {
            registradores[i].valor = valor;
            return;
        }
    }
    printf("Erro: Registrador com nome '%s' não encontrado.\n", nome);
}

// Print de todos os Registradores

void mostrarRegistradores(struct registrador registradores[]){
for (int i = 0; i < 35; i++) {
        printf("%d. %s = %d\n",
            registradores[i].id,
            registradores[i].nome,
            registradores[i].valor);
    }
}