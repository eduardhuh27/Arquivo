#include <stdio.h>

int repeticao(char nomeArq[], char repetido);


int main ()
{
    char nome_arq[30];
    char remover;
    int resposta;

    printf("Nome do arquivo:");
    scanf("%s",nome_arq);
    
    printf("Caracter que vai ser contado:");
    scanf(" %c",&remover);

    resposta=repeticao(nome_arq,remover);
    if(resposta==0)
    {
        printf("\n\nERRO, nao foi possivel abrir o arquivo!");
    }
    else
    {
        printf("%d caracteres %c repetidos!",resposta,remover);
    }
   return 0;
}
int repeticao (char nomeArq[],char repetido)
{
    FILE *arq;
    char ch;
    int cont=0;

    arq=fopen(nomeArq,"r");
   

    if(arq==NULL)
    {
        fclose(arq);
       

        return 0;
    }
   
    while(fscanf(arq,"%c",&ch)!=EOF)
    {
        if(repetido==ch)
        {
         cont++;  
        }
       
    }
   
    fclose(arq);
    
    return cont;

}
