#include <stdio.h>
#include <string.h>

void ULA() {
    
}

void AttPC(int tag) {
    if (tag == -1){
        tag = getRegistradorNome(resgistradores, "pc");    
        tag++;
    } 
    setRegistradorNome(resgistradores, "pc", tag);
    mostrarRegistradores(resgistradores);
}

void memoriaInstrucao(char func[3], char r0[5], char r1[5], char r2[5], int tag){
    if (strcmp(func, "li") == 0) {
            printf("Instrução: li\n");
            // Lógica específica para "li"
        } else if (strcmp(func, "move") == 0) {
            printf("Instrução: move\n");
            // Lógica específica para "move"
        } else if (strcmp(func, "add") == 0) {
            printf("Instrução: add\n");
            // Lógica específica para "add"
        } else if (strcmp(func, "bge") == 0) {
            printf("Instrução: bge\n");
            // Lógica específica para "bge"
        } else if (strcmp(func, "addi") == 0) {
            printf("Instrução: addi\n");
            // Lógica específica para "addi"
        } else if (strcmp(func, "J") == 0) {
            printf("Instrução: J\n");
            // Lógica específica para "J"
        } else if (strcmp(func, "div") == 0) {
            printf("Instrução: div\n");
            // Lógica específica para "div"
        } else if (strcmp(func, "mflo") == 0) {
            printf("Instrução: mflo\n");
            // Lógica específica para "mflo"
        } else if (strcmp(func, "mfhi") == 0) {
            printf("Instrução: mfhi\n");
            // Lógica específica para "mfhi"
        } else {
            printf("Instrução desconhecida: %s\n", func);
        }
}


int main(){
    
    AttPC(-1);
    return 0;
}
