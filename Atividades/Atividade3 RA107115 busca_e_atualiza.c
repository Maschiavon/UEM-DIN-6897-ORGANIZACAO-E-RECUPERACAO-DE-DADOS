#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM_MAX_REG 256
#define DELIM_STR "|"
#define TAM_STR 50

int input(char*, int);
short leia_reg(FILE*, char*, int);
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
    setlocale(LC_ALL, "Portuguese");
    menu_principal();
    //FILE *entrada;
    //char nome_arq[TAM_STR];
    //char buffer[TAM_MAX_REG];
    //short comp_reg;
    //int conta_reg = 0, conta_campo, escolha;
    //char *campo, *sobrenome, abrir[2];
    //entrada = fopen(nome_arq, "r");
    //if (entrada == NULL) {
    //    printf("Erro na abertura do arquivo --- programa abortado\n");
    //    exit(1);
    //}
    return 0;
}
void menu_principal(){
    char escolha[TAM_STR];
    printf("PROGRAMA PARA INSERÇÃO E ALTERAÇÃO DE REGISTROS\nSUAS OPÇÕES SÃO:\n1. Inserir um novo registro\n2. Buscar um registro por RNN para alterações\n3. Terminar programa\nDigite o numero de sua escolha: ");
    //scanf("%d",&escolha);
    input(escolha,TAM_STR);
    if(atoi(escolha) == 1){
       inserir_registro();
    }
    else if(atoi(escolha) == 2){
      // busca_rnn();
    }
    else if(atoi(escolha) == 3){
        printf("\aFechando o programa --- programa abortado\n");
        exit(0);
    } else {
        printf("\aFaça uma escolha valida --- restaurnado....\n");
        menu_principal();
    }
}

int inserir_registro(){
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
    menu_principal();
}

/*int busca_rnn(){
    char rrn[TAM_STR];
    int Vrrn
    printf("\n\nDigite o RRN do registro: ");
    input(rrn, TAM_STR);
    return atoi(rrn);
}*/

short leia_reg(FILE *entrada, char * buffer, int tam){
    short comp_reg;

    if (fread(&comp_reg, sizeof (comp_reg), 1, entrada) == 0) {
        return 0;
    }

    if (comp_reg < tam) {
        comp_reg = fread(buffer, sizeof (char), comp_reg, entrada);
        buffer[comp_reg] = '\0';
        return comp_reg;
    }
    else {
        printf("Buffer overflow\n");
        return 0;
    }
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

void concatena_buffer(char *buffer, char *campo){
    strcat(buffer, campo);
    strcat(buffer, DELIM_STR);
}
