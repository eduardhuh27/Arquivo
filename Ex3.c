#include <stdio.h>

int contarLetras(char nomrArq[]);

int main()
{
    char nomeArq[30];
    int resposta;

    printf("Entre com o nome do arquivo:");
    scanf(" %s",nomeArq);

    resposta = contarLetras(nomeArq);

    if(!resposta)
    {
        printf("ERRO: nao foi possivel abrir o arquivo!!");
    }
    else
    {
        printf("O arquivo %s possui %d letras.",nomeArq,resposta);
    }
    return 0;
}

int contarLetras(char nomeArq[])
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
        if( (lendo>='a') && (lendo<='z'))
        {
             cont++;
         }
    }

    fclose(arq);
    return cont;

}