#include <stdio.h>

int numeros (char nomeArq[] );
int crescente(int organizado[10],int tamanho);

int main()
{
    char nomeArq[30];
    int resposta;

    printf("Entre com o nome do arquivo:");
    scanf(" %s",nomeArq);

    resposta = numeros (nomeArq);

    if(!resposta)
    {
        printf("ERRO: nao foi possivel abrir o arquivo!!");
    }
    if(resposta==-1)
    {
        printf("O arquivo possui numeros mas nao estao em ordem crescente ");
    }
    else
    {
        printf("O arquivo possui numeros e estao em ordem crescente");
    }
    return 0;
} 
int tamanho (char nomeArq[])
{
    int i=0; 
    char lendo;
    FILE *arq;
    

    arq=fopen(nomeArq,"r");

    if(arq==NULL)
    {
        return 0;
    }
    while( fscanf(arq,"%c",&lendo)!=EOF)
    {
        i++;
    }
    
    return i;
}

int numeros (char nomeArq[])
{
    int i=0,resposta; 
    char lendo;
    FILE *arq;
    char organizado[tamanho(nomeArq)];

    arq=fopen(nomeArq,"r");

    if(arq==NULL)
    {
        return 0;
    }

    while( fscanf(arq,"%c",&lendo)!=EOF)
    {
        if((lendo >= '0') && (lendo <= '9' ))
        {    
            organizado[i]=lendo;
            i++;
        }
    }

    fclose(arq);
    resposta = crescente(organizado,i);

    return resposta;
}

int crescente(int organizado[10],int tamanho)
{
    int i;

    for(i=0;i<tamanho;i++)
    {
        if(organizado[i]>organizado[i+1])
        {
            return -1;
        }
    }
    return 1;


}