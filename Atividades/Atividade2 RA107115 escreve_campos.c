#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *pont_arq;
    pont_arq = fopen("arquivo.txt", "a");
    if(!pont_arq){ //se o arquivo n�o existe cria
       pont_arq = fopen("arquivo.txt", "w+");
    }

    char Sobrenome[20], Nome[20], Endereco[20], Cidade[20], Estado[20], CEP[20];
    int comprimento;

    printf("Escreva os dados das Pessoas (Sobrenome, Nome, Endereco, Cidade, Estado, CEP)\n");
    printf("Sobrenome: ");
    fgets(Sobrenome,20,stdin);
    Sobrenome[strlen(Sobrenome)-1] = '\0';

    comprimento = strlen(Sobrenome);
    while(comprimento>0){

          printf("Nome: ");
          fgets(Nome,20,stdin);
          Nome[strlen(Nome)-1] = '\0';

          printf("Endereco: ");
          fgets(Endereco,20,stdin);
          Endereco[strlen(Endereco)-1] = '\0';

          printf("Cidade: ");
          fgets(Cidade,20,stdin);
          Cidade[strlen(Cidade)-1] = '\0';

          printf("Estado: ");
          fgets(Estado,20,stdin);
          Estado[strlen(Estado)-1] = '\0';

          printf("CEP: ");
          fgets(CEP,20,stdin);
          CEP[strlen(CEP)-1] = '\0';

          fputs(strcat(Sobrenome,"|"), pont_arq);
          fputs(strcat(Nome,"|"), pont_arq);
          fputs(strcat(Endereco,"|"), pont_arq);
          fputs(strcat(Cidade,"|"), pont_arq);
          fputs(strcat(Estado,"|"), pont_arq);
          fputs(strcat(CEP,"\n"), pont_arq);

          printf("Sobrenome: ");
          fgets(Sobrenome,20,stdin);
          Sobrenome[strlen(Sobrenome)-1] = '\0';

          comprimento = strlen(Sobrenome);
    }

    fclose(pont_arq);
}
