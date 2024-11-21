#include "Funcoes/Registradores.h"
#include "Funcoes/MemoriaInstrucao.h"
#include "Funcoes/Processador.h"

int main() {
    struct registrador registradores[35];
    inicializarRegistradores(registradores);
    mostrarRegistradores(registradores);
    teste();
    return 0;
}