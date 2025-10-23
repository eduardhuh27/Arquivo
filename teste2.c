#include <stdio.h>


void main() {
    int i;
    FILE *arq;
    //criando uma variavel do tipo FILE*
    
    char nomeArquivo[30];


    printf("Nome do arquivo:");
    scanf("%s",nomeArquivo);
    
    if(lerOArquivo(nomeArquivo)==0)
    {
        printf("\n Arquivo %s nao aberto",nomeArquivo);
    }
}