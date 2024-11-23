#include "Funcoes/Registradores.h"
#include "Funcoes/MemoriaInstrucao.h"
#include "Funcoes/Processador.h"
#include <stdlib.h>

int main() {
    struct registrador *registradores = malloc(35 * sizeof(struct registrador));
    inicializarRegistradores(registradores);
    initPc(registradores);
    attPC(-1);
    memoriaInstrucao("addi", "$t0", "$t0", "1", -1);
    // int controlador = 0;
    // while (controlador != -1) {
    //     int linhaAtual = getRegistradorNome(registradores, "pc");
    //     controlador = read(linhaAtual);
    // }
    mostrarRegistradores(registradores);
    return 0;
}