#include <stdio.h>

int escreverArquivo (char nomeArq[],int numero);

int main ()
{
    char nome_arq[30];
    int numero;

    printf("Nome do arquivo:");
    scanf("%s",nome_arq);
    
    printf("Numero:");
    scanf("%d",&numero);

    if(escreverArquivo(nome_arq,numero)==0)
    {
        printf("\n\nERRO, nao foi possivel abrir o arquivo!\n\n");
    }
    else
    {
        printf("O arquivo preenchido com sucesso!\n\n");

    }   
    return 0;
}
int escreverArquivo (char nomeArq[],int numero)
{
    FILE *arq;
    int i;

    arq=fopen(nomeArq,"w");

    
    if(arq==NULL)
    {
        return 0;
    }

    for(i=0;i<=numero;i++)
    {
        fprintf(arq,"%d\n",i);
    }
    fclose(arq);

    return 1;

}