#ifndef Processador_h
#define Processador_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct registrador *registradoresPC;

typedef struct
{
    int quociente;
    int resto;
} resultado;

void initPc(struct registrador *registradores)
{
    registradoresPC = registradores;
}

void tabelaEstrutural(char func[], char r0[], char r1[], char r2[]) {
    char funcao[20];
    char *ra0, *ra1, *ra2, *instruct;
    unsigned int funct;
    unsigned int cod;
    char pseudo[20] = "";

    instruct = (char*)malloc(100);
    instruct[0] = '\0';

    if (strcmp(func, "li") == 0 || strcmp(func, "addi") == 0 || strcmp(func, "move") == 0 || strcmp(func, "bge") == 0 || strcmp(func, "mflo") == 0 || strcmp(func, "mfhi") == 0) {
        strcpy(funcao, "I");

        if (strcmp(func, "li") == 0) {
            funct = 0;
            cod = 0;
            strcat(pseudo, "Pseudo-Instrucao");
        }
        else if (strcmp(func, "addi") == 0) {
            funct = 0b001000;
            cod = 0b001000;
        }
        else if (strcmp(func, "move") == 0) {
            funct = 0;
            cod = 0;
            strcat(pseudo, "Pseudo-Instrucao");
        }
        else if (strcmp(func, "bge") == 0) {
            funct = 0;
            cod = 0;
            strcat(pseudo, "Pseudo-Instrucao");
        }
        else if (strcmp(func, "mflo") == 0) {
            funct = 0b010010;
            cod = 0b010010;
        }
        else if (strcmp(func, "mfhi") == 0) {
            funct = 0b010000;
            cod = 0b010000;
        }

    } else if (strcmp(func, "add") == 0 || strcmp(func, "div") == 0) {
        strcpy(funcao, "R");

         if (strcmp(func, "add") == 0) {
            funct = 0b100000;
            cod = 0;
        }
        else if (strcmp(func, "div") == 0) {
            funct = 0b011010;
            cod = 0;
        }

    } else if (strcmp(func, "J") == 0) {
        strcpy(funcao, "J");
        funct = 0b000010;
        cod = 0b000010;
    } else {
        printf("Função desconhecida!\n");
        return;
    }
    
    snprintf(instruct, 100, "%s ", func);

    char funcao_completa[30];
    snprintf(funcao_completa, sizeof(funcao_completa), "Funcao %s", funcao);

    
    if (r0 == NULL || strcmp(r0, "") == 0) {
        ra0 = "-";  
    } else {
        ra0 = r0;
        strcat(instruct, ra0); 
        if(strcmp(func, "J") != 0)
            strcat(instruct, ", ");
    }

    if (r1 == NULL || strcmp(r1, "") == 0) {
        ra1 = "-";  
    } else {
        ra1 = r1; 
        strcat(instruct, ra1); 
    }

    if (r2 == NULL || strcmp(r2, "") == 0) {
        ra2 = "-";  
    } else {
        ra2 = r2;  
        strcat(instruct, ", "); 
        strcat(instruct, ra2); 
    }

    printf("  %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", 
           " ", "Cod. Instrucao", "1 Operando", "2 Operando", "3 Operando", "shamt", "Funct", "Instrucao MIPS");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-15u | %-15s | %-15s | %-15s | %-15s | %-15u | %-15s | %-15s\n", 
           funcao_completa, cod , ra1, ra2, ra0, "0", funct, instruct, pseudo);
    printf("==================================================================================================================================================\n");
}

resultado ula(char op, int n1, int n2)
{
    resultado resultados = {0, 0};

    switch (op)
    {
    case 'a':                          
        resultados.quociente = n1 + n2; 
        break;
    case 'b':
            resultados.quociente = (n1 >= n2) ? 1 : 0;
        break;
    case 'd':
        if (n2 != 0)
        {
            resultados.quociente = n1 / n2;
            resultados.resto = n1 % n2;
        }
        else
        {
            printf("Erro: Divisão por zero não é permitida.\n");
        }
        break;
    default:
        printf("Operação inválida.\n");
        break;
    }

    return resultados;
}

void attPC(int tag)
{
    if (tag == -1)
    {
        tag = getRegistradorNome(registradoresPC, "pc");
        tag++;
    }
    setRegistradorNome(registradoresPC, "pc", tag);
}

void memoriaInstrucao(char func[], char r0[], char r1[], char r2[], int tag)
{
    printf("\n");
    tabelaEstrutural(func, r0, r1, r2);
    printf("\n");
    if (strcmp(func, "li") == 0)
    {
        int numR1 = atoi(r1);
        setRegistradorNome(registradoresPC, r0, numR1);
        attPC(tag);
    }
    else if (strcmp(func, "move") == 0)
    {
        int r1value = getRegistradorNome(registradoresPC, r1);
        setRegistradorNome(registradoresPC, r0, r1value);
        attPC(tag);
    }
    else if (strcmp(func, "add") == 0)
    {
        int numR1 = getRegistradorNome(registradoresPC, r1);
        int numR2 = getRegistradorNome(registradoresPC, r2);
        resultado result = ula('a', numR1, numR2);
        setRegistradorNome(registradoresPC, r0, result.quociente);
        attPC(tag);
    }
    else if (strcmp(func, "bge") == 0)
    {
        int numR0 = getRegistradorNome(registradoresPC, r0);
        int numR1 = getRegistradorNome(registradoresPC, r1);
        resultado result = ula('b', numR0, numR1);
        if(result.quociente == 1)
            attPC(tag);
        else
            attPC(-1);
    }
    else if (strcmp(func, "addi") == 0)
    {
        int numR1 = getRegistradorNome(registradoresPC, r1);
        int numR2 = atoi(r2);
        resultado result = ula('a', numR1, numR2);
        setRegistradorNome(registradoresPC, r0, result.quociente);
        attPC(tag);
    }
    else if (strcmp(func, "J") == 0)
    {
        attPC(tag);
    }
    else if (strcmp(func, "div") == 0)
    {
        int numR0 = getRegistradorNome(registradoresPC, r0);
        int numR1 = getRegistradorNome(registradoresPC, r1);
        resultado result = ula('d', numR0, numR1);
        setRegistradorNome(registradoresPC, "lo", result.quociente);
        setRegistradorNome(registradoresPC, "hi", result.resto);
        attPC(tag);
    }
    else if (strcmp(func, "mflo") == 0)
    {
        int loValue = getRegistradorNome(registradoresPC, "lo");
        setRegistradorNome(registradoresPC, r0, loValue);
        attPC(tag);
    }
    else if (strcmp(func, "mfhi") == 0)
    {
        int hiValue = getRegistradorNome(registradoresPC, "hi");
        setRegistradorNome(registradoresPC, r0, hiValue);
        attPC(tag);
    }
    else
    {
        printf("Instrução desconhecida: %s\n", func);
    }

    printf("\n");
    mostrarRegistradores(registradoresPC);
    printf("\n");
}

#endif