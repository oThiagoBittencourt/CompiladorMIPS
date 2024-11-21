#include "Funcoes/Registradores.h"
#include "Funcoes/MemoriaInstrucao.h"
#include "Funcoes/Processador.h"

int main() {
    struct registrador registradores[35];
    inicializarRegistradores(registradores);
    mostrarRegistradores(registradores);
    while (0) {
        read(1);
    }
    return 0;
}