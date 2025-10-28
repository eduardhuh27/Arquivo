#include <stdio.h>

int contarCaracter(char nomrArq[]);

int main()
{
    char nomeArq[30];
    int resposta;

    printf("Entre com o nome do arquivo:");
    scanf(" %s",nomeArq);

    resposta = contarCaracter(nomeArq);

    if(!resposta)
    {
        printf("ERRO: nao foi possivel abrir o arquivo!!");
    }
    else
    {
        printf("O arquivo %s possui %d caracteres.",nomeArq,resposta);
    }
    return 0;
}

int contarCaracter (char nomeArq[])
{
    FILE *arq;
    int cont=0;
    char lendo;

    arq=fopen(nomeArq,"r");
    
    if(arq==NULL)
    {
        return 0;
    }
    while(fscanf(arq,"%c",&lendo)!=EOF)
    {
        // if( (lendo>=65) && (lendo<=90))
        // {
             cont++;
        // }
    }

    fclose(arq);
    return cont;

}