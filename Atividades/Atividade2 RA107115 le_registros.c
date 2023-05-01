#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM_CH '|'
#define DELIM_CH2 '\n'
#define TAM_STR 50

int leia_campo(FILE *a, char *, int );

int main(){
    FILE *arq;
    char campo[TAM_STR];
    char nome_arq[TAM_STR];
    int conta_campo, conta_registro;
    int tam;

    printf("Digite o nome do arquivo a ser lido: ");
    fgets(nome_arq, TAM_STR, stdin);
    nome_arq[strlen(nome_arq)-1] = '\0';

    if ((arq = fopen(nome_arq, "r")) == NULL) {
        printf("Erro na abertura do arquivo --- programa abortado\n");
        exit(1);
    }

    conta_campo = 0;
    conta_registro = 0;
    tam = leia_campo(arq, campo, TAM_STR);
    printf("Registro #%d\n", ++conta_registro);
    while (tam > 0) {
        if((conta_campo/6) > conta_registro-1){
            printf("Registro #%d\n", ++conta_registro);
            conta_campo = 0;
        }
        printf("\tcampo #%d: %s\n", ++conta_campo, campo);
        tam = leia_campo(arq, campo, TAM_STR);

    }

    fclose(arq);
    return 0;
}

int leia_campo(FILE *arq, char *campo, int tam){
    int i = 0;
    int asc2 = 0;
    char ch = fgetc(arq);

    while (ch != EOF && ch != DELIM_CH && ch != DELIM_CH2){
        asc2 = ch;
        if (asc2 >= 32 && asc2 <= 126){
            if (tam > 1) {
                campo[i] = ch;
                i++;
                tam--;
            }
            ch = fgetc(arq);
        } else {
            ch = fgetc(arq);
        }

    }
    campo[i] = '\0';
    return i;
}
