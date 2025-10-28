#include <stdio.h>

int copiardecres (char nomeArq[]);
int descrescente (float numeros[],int quantidade);
int repeticao (float numeros[],int i, float lendo);
int tamanho (char nomeArq[]);

int main ()
{
    int resposta;
    char nomeArq[30];

    printf("Entre comm o nome do arquivo:");
    scanf("%s",nomeArq);

    resposta=copiardecres(nomeArq);

    if(!resposta)
    {
        printf("ERRO: nao foi possivel abrir o arquivo");
    }
    

}
int tamanho (char nomeArq[])
{
    int i=0; 
    float lendo;
    FILE *arq;
    

    arq=fopen(nomeArq,"r");

    if(arq==NULL)
    {
        return 0;
    }
    while( fscanf(arq,"%f",&lendo)!=EOF)
    {
        i++;
    }
    fclose(arq);
    return i;
}

int copiardecres (char nomeArq[])
{

    int i=0,resposta,quantidade=tamanho(nomeArq),j=0; 
 float lendo;
    FILE *arq,*arqB;
    float organizado[quantidade];

    arq=fopen(nomeArq,"r");
    arqB=fopen("Novo.txt","w");

    if(arq==NULL || arqB==NULL)
    {
        fclose(arq);
        fclose(arqB);
        return 0;
    }

    while( fscanf(arq,"%f",&lendo)!=EOF)
    {
        if(repeticao(organizado,i,lendo)==0)
        { 
            organizado[i]=lendo;
            i++;
        }
    }

    fclose(arq);

    resposta = descrescente(organizado,i);
    
    if(resposta==1)
    {
        while(i>j)
        {
            fprintf(arqB,"%.1f\n",organizado[j]);
            j++;
        }
    }
    fclose (arqB);
    return resposta;

}

int descrescente(float numeros[],int quantidade)
{   
    int i,j;
    float temp;
    
    for(i=0;i<quantidade-1;i++)
    {
        for(j=0;j<quantidade-1;j++)
        {
            if(numeros[j]<numeros[j+1])
            {
                temp=numeros[j+1];
                numeros[j+1]=numeros[j];
                numeros[j]=temp;

             }  
         }
    }
    return 1;
}

int repeticao (float numeros[],int i ,float lendo)
{
    int j;

    for(j=0;j< i;j++)
    {
            if(numeros[j]==lendo)
            {
                return 1;
            }
        
    }
    return 0;
}