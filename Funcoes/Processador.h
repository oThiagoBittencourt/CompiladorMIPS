#ifndef Processador_h
#define Processador_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

resultado ula(char op, int n1, int n2)
{
    resultado resultados = {0, 0};

    switch (op)
    {
    case 'a':                          
        resultados.quociente = n1 + n2; 
        break;
    case 'b':
        resultados.quociente = n1 - n2;
        if()
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
        // Lógica específica para "bge"
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
        printf("Instrução: J\n");
        // Lógica específica para "J"
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
}

#endif