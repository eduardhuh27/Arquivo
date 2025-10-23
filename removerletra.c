#include <stdio.h>

int removercaracter (char nomeArq[],char remover);


void main ()
{
    char nome_arq[30];
    char remover;
    int resposta;

    printf("Nome do arquivo:");
    scanf("%s",nome_arq);
    
    printf("Caracter que vai ser removido:");
    scanf(" %c",&remover);

    resposta=removercaracter(nome_arq,remover);
    if(resposta==-1)
    {
        printf("\n\nERRO, nao foi possivel abrir o arquivo!");
    }
    else
    {
        printf("%d caracteres %c removidos!",resposta,remover);
    }
    
}
int removercaracter (char nomeArq[],char remover)
{
    FILE *arq,*temp;
    char ch;
    int cont=0;

    arq=fopen(nomeArq,"r");
    temp=fopen("temp.txt","w");

    if(arq==NULL)
    {
        fclose(arq);
        fclose(temp);

        return -1;
    }
   
    while(fscanf(arq,"%c",&ch)!=EOF)
    {
        if(remover!=ch)
        {
            fprintf(temp,"%c",ch);
        }
       else 
       {
        cont++;
       }
    }
   
    fclose(arq);
    fclose(temp);

    return cont;

}
