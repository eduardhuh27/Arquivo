#include <stdio.h>

int copiarArquivo (char nomeArq[]);

void main ()
{
    char nome_arq[30];
    

    printf("Nome do arquivo:");
    scanf("%s",nome_arq);
    
    
    if(copiarArquivo(nome_arq)==0)
    {
        printf("\n\nERRO, nao foi possivel abrir o arquivo!");
    }
    else
    {
        printf("Arquivo copiado com sucesso!");
    }
    
}
int copiarArquivo (char nomeArq[])
{
    FILE *arq,*temp;
    char ch;

    arq=fopen(nomeArq,"r");
    temp=fopen("temp.txt","w");

    if(arq==NULL)
    {
        fclose(arq);
        fclose(temp);

        return 0;
    }
   
    while(fscanf(arq,"%c",&ch)!=EOF)
    {
        fprintf(temp,"%c",ch);
    }
   
    fclose(arq);
    fclose(temp);

    return 1;

}