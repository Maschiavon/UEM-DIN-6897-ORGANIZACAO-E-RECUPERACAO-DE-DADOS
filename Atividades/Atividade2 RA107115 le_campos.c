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
    int conta_campo;
    int tam;

    printf("Digite o nome do arquivo a ser lido: ");
    fgets(nome_arq, TAM_STR, stdin);
    nome_arq[strlen(nome_arq)-1] = '\0';

    if ((arq = fopen(nome_arq, "r")) == NULL) {
        printf("Erro na abertura do arquivo --- programa abortado\n");
        exit(1);
    }

    conta_campo = 0;
    tam = leia_campo(arq, campo, TAM_STR);
    while (tam > 0) {
        printf("\tcampo #%d: %s\n", ++conta_campo, campo);
        tam = leia_campo(arq, campo, TAM_STR);
    }

    fclose(arq);
    return 0;
}

int leia_campo(FILE *arq, char *campo, int tam){
    int i = 0;
    char ch = fgetc(arq);

    while (ch != EOF && ch != DELIM_CH && ch != DELIM_CH2){
        if (tam > 1) {
            campo[i] = ch;
            i++;
            tam--;
        }
        ch = fgetc(arq);
    }
    campo[i] = '\0';
    return i;
}
