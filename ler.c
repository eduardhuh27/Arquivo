#include <stdio.h>

int lerArquivo (char nomeArq[]);

void main ()
{
    char nome_arq[30];
    

    printf("Nome do arquivo:");
    scanf("%s",nome_arq);
    
    
    if(lerArquivo(nome_arq)==0)
    {
        printf("\n\nERRO, nao foi possivel abrir o arquivo!");
    }
    
}
int lerArquivo (char nomeArq[])
{
    FILE *arq;
    char ch;

    arq=fopen(nomeArq,"r");
 
    if(arq==NULL)
    {
        return 0;
    }
   
    while(fscanf(arq,"%c",&ch)!=EOF)
    {
        printf("%c",ch);
    }
   
    fclose(arq);

    return 1;

}