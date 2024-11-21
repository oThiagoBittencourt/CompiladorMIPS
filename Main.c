#include "Funcoes/Registradores.h"
#include "Funcoes/MemoriaInstrucao.h"
#include "Funcoes/Processador.h"

int main() {
    struct registrador registradores[35];
    inicializarRegistradores(registradores);
    AttPC(-1);
    // mostrarRegistradores(registradores);
    int controlador = 0;
    while (controlador != -1) {
        int linhaAtual = getRegistradorNome(registradores, "pc");
        controlador = read(linhaAtual);
    }
    return 0;
}