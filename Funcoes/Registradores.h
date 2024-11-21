#include <stdio.h>
#include <string.h>

struct registrador{
char nome[5];
int numero, valor;
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
        registradores[i].numero = i;
        registradores[i].valor = 0;
    }
}

void mostrarRegistradores(struct registrador registradores[]){
for (int i = 0; i < 35; i++) {
        printf("%d. %s = %d\n",
            registradores[i].numero,
            registradores[i].nome,
            registradores[i].valor);
    }
}