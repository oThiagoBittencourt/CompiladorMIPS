#include <stdio.h>
#include <string.h>
#include "Processador.h"

int read(int line) {
    printf("%d", line);
    FILE *file;
    char filename[] = "../Arquivos/Arquivo.txt";
    char linha[32];
    char *p1, *p2, *p3, *p4;

    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while (fgets(linha, sizeof(linha), file) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';

        if (strlen(linha) == 0) {
            continue;
        }

        p1 = p2 = p3 = p4 = NULL;

        p1 = strtok(linha, " ");
        p2 = strtok(NULL, " ");
        p3 = strtok(NULL, " ");
        p4 = strtok(NULL, " ");

        if (p2 == NULL) {
            continue;
        }

        if (strcmp(p1, "bge") == 0) {

        }
        else if (strcmp(p1, "J") == 0) {

        }
        else {
            // Instrucao(p1, p2, p3, p4);
        }
    }

    fclose(file);

    return 0;
}
