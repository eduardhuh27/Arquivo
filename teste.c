#include <stdio.h>

int ecreverNoArquivo(char nomeArq[],int n);
int lerOArquivo(char nomeArq[]);

int main() {
    int i;
    FILE *arq;//criando uma variavrl do tipo FILE*
    char nomeArquivo[30];
    //int numero;

    printf("Nome do arquivo:");
    scanf("%s",nomeArquivo);
    
    if(lerOArquivo(nomeArquivo)==0)
    {
        printf("\n Arquivo %s nao aberto",nomeArquivo);
    }
    // printf("\n\n Numero:");
    // scanf("%d",&numero);


   /* if(ecreverNoArquivo(nomeArquivo,numero)==1)
    {
        printf("\n Arquivo %s criado com sucesso!",nomeArquivo);
    }
    else
        {
            printf("\n Arquivo %s nao aberto",nomeArquivo);
        }
    

   //associar a variavel FILE* a um arquivo + abri o arquivo
     arq = fopen("teste.txt","w");
        
     if(arq==NULL)   // ou (!arq)
     {
         printf("\n\n ERRO: arquivo nao aberto!\n\n");
     }
 else
     {   
         //manipular o arquivo
       for(i=0;i<=1000;i++)
         {
             fprintf(arq,"%d\n",i);
         }

         //Fechar o arquivo
       fclose(arq);
*/
        }

int ecreverNoArquivo(char nomeArq[],int n)
{
    int i;
    FILE *arq;

    arq = fopen(nomeArq,"w");

    if(arq==NULL)
    {

        return 0;
    }
    else
    {
        for(i=0;i<=n;i++)
        {
            fprintf(arq,"\n%d",i);
        }
        fclose(arq);
        return 1;
    }  
}
int lerOArquivo (char nomeArq[])
{
    FILE *arq;
    char numero;

    arq = fopen(nomeArq,"r");

    if(arq==NULL)
    {
        return 0;
    }
    else 
    {
        while(fscanf(arq,"%c",&numero)!=EOF)
        {
            printf("%c\n",numero);
        }
    }
    fclose(arq);
    return 1;

}