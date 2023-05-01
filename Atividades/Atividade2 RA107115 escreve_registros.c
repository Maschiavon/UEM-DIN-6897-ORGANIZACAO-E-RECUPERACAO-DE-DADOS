#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_REG 256
#define DELIM_STR "|"
#define TAM_STR 50

int input(char *, int);
void concatena_buffer(char *, char *);

char * prompt[] = {
    "Digite o sobrenome ou <ENTER> para sair: ",
    "                          Primeiro nome: ",
    "                               Endereco: ",
    "                                 Cidade: ",
    "                                 Estado: ",
    "                                    CEP: ",
    ""
};

int main(){
    FILE *arq;
    char buffer[TAM_MAX_REG];
    char campo[TAM_STR];
    char nome_arq[TAM_STR];
    int i;
    short comp_reg;
    int comprimento;

    printf("Digite o nome do arquivo a ser criado: ");
    input(nome_arq,TAM_STR);

    if ((arq = fopen(nome_arq, "wb")) == NULL) {
        printf("Erro na criacao do arquivo --- programa abortado\n");
        exit(1);
    }

    printf("\n\n%s", prompt[0]);
    comprimento = input(campo, TAM_STR);

    while (comprimento > 0){

        buffer[0] = '\0';
        concatena_buffer(buffer, campo);

        for(i = 1; prompt[i] != ""; i++){
            printf("%s", prompt[i]);
            input(campo, TAM_STR);
            concatena_buffer(buffer, campo);
        }

        comp_reg = strlen(buffer);
        fwrite(&comp_reg, sizeof (comp_reg), 1, arq);
        fwrite(buffer, sizeof (char), comp_reg, arq);

        printf("\n\n%s", prompt[0]);
        comprimento = input(campo, TAM_STR);
    }

    fclose(arq);
    return 0;
}

void concatena_buffer(char *buffer, char *campo){
    strcat(buffer, campo);
    strcat(buffer, DELIM_STR);
}

int input(char * str, int size) {
    int i = 0;
    char c = getchar();
    while (c != '\n') {
        if (size > 1) {
            str[i] = c;
            i++;
            size--;
        }
        c = getchar();
    }
    str[i] = '\0';
    return i;
}
