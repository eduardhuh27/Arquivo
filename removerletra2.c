#include <stdio.h>

int removercaracter (char nomeArq[],char remover);
int copiarArquivo (char nomeArqO[],char nomeArqD[]);

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

    copiarArquivo (nomeArq,"temp.txt");

    remove("temp.txt");

    return cont;

}
int copiarArquivo (char nomeArqO[],char nomeArqD[])
{
    FILE *arq,*temp;
    char ch;

    arq=fopen(nomeArqO,"w");
    temp=fopen(nomeArqD,"r");

    if(arq==NULL)
    {
        fclose(arq);
        fclose(temp);

        return 0;
    }
   
    while(fscanf(temp,"%c",&ch)!=EOF)
    {
        fprintf(arq,"%c",ch);
    }
   
    fclose(arq);
    fclose(temp);

    return 1;

}