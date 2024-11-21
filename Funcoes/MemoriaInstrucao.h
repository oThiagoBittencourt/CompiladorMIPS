#include <stdio.h>

int teste() {
    FILE *file;
    char filename[] = "Arquivos/Arquivo.txt"; // Caminho relativo ao arquivo
    char linha[256]; // Buffer para armazenar cada linha do arquivo

    // Abrindo o arquivo no modo leitura ("r")
    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lendo o arquivo linha por linha
    while (fgets(linha, sizeof(linha), file) != NULL) {
        printf("%s", linha); // Imprime a linha lida
    }

    // Fechando o arquivo
    fclose(file);

    return 0;
}
