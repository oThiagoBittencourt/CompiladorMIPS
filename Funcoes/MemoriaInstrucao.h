#include <stdio.h>
#include <string.h>
#include "Processador.h"

int read(int pc) {
    FILE *file;
    char filename[] = "../Arquivos/Arquivo.txt";
    char linha[32];
    char linhaTAG[32];
    char *func, *r0, *r1, *r2, *tag;
    int tag_id = -1;
    int linha_atual = 1;

    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    while (fgets(linha, sizeof(linha), file) != NULL) {
        
        if (linha_atual != pc) {
            linha_atual++;
            continue;
        }
        linha[strcspn(linha, "\n")] = '\0';

        if (strlen(linha) == 0) {
            attPC(tag_id);
            fclose(file);
            return 0;
        }

        func = r0 = r1 = r2 = tag = NULL;

        func = strtok(linha, " ");
        r0 = strtok(NULL, " ");
        r1 = strtok(NULL, " ");
        r2 = strtok(NULL, " ");

        if (r0 == NULL) {
            attPC(tag_id);
            fclose(file);
            return 0;
        }

        if (strcmp(func, "bge") == 0) {
            rewind(file);
            int linhaBusca_atual = 1;
            while (fgets(linhaTAG, sizeof(linhaTAG), file) != NULL) {
                linhaTAG[strcspn(linhaTAG, "\n")] = '\0';
                tag = strtok(linhaTAG, " ");
                if (!strstr(tag, r2)) {
                    linhaBusca_atual++;
                    continue;
                }
                printf("%d\n", linhaBusca_atual);
                tag_id = linhaBusca_atual;
                break;
            }
            // Instrucao(func, r0, r1, r2, tag_id);
        }
        else if (strcmp(func, "J") == 0) {
            rewind(file);
            int linhaBusca_atual = 1;
            while (fgets(linhaTAG, sizeof(linhaTAG), file) != NULL) {
                linhaTAG[strcspn(linhaTAG, "\n")] = '\0';
                tag = strtok(linhaTAG, " ");
                if (!strstr(tag, r0)) {
                    linhaBusca_atual++;
                    continue;
                }
                tag_id = linhaBusca_atual;
                break;
            }
            // Instrucao(func, r0, r1, r2, tag_id);
        }
        else {
            // Instrucao(func, r0, r1, r2, tag_id);
        }

        fclose(file);
        return 0;
    }

    fclose(file);
    return -1;
}