#include <stdio.h>

int intercessao (char nomeArq[],char nomeArqB[]);
int crescente(char conteudo[],int quantidade);
int tamanho (char nomeArq[]);
int repeticao (char conteudo[],int i ,char lendo);

int main ()
{
    int resposta;
    char nomeArq[30];
    char nomeArqB[30];

    printf("Entre com nome do arquivo A:");
    scanf("%s",nomeArq);
    printf("Entre com nome do arquivo B:");
    scanf(" %s",nomeArqB);

    resposta=intercessao(nomeArq,nomeArqB);

    if(resposta==0)
    {
        printf("ERRO: nao foi possivel abrir o arquivo!!");

    }
}

int tamanho (char nomeArq[])
{
    int i=0; 
    char lendo;
    FILE *arq;

    arq=fopen(nomeArq,"r");
    

    if(arq==NULL )
    {
        
        return 0;
    }
    while( fscanf(arq,"%c",&lendo)!=EOF  )
    {
        i++;
    }

    fclose(arq);
    return i;
}

int intercessao (char nomeArq[],char nomeArqB[])
{

    int i=0,resposta,quantidadeA=tamanho(nomeArq),quantidadeB=tamanho(nomeArqB),j=0; 
    int k,l,m=0;
    char lendo;
    FILE *arq,*arqB,*arqC;
    char organizado[(quantidadeA+quantidadeB)];
    char arquivoB[quantidadeB];
    char arquivoA[quantidadeA];

    arq=fopen(nomeArq,"r");
    arqB=fopen(nomeArqB,"r");
    arqC=fopen("OVO2.txt","w");

    if(arq==NULL || arqB==NULL || arqC==NULL)
    {
        fclose(arq);
        fclose(arqB);
        fclose(arqC);
        return 0;
    }

    while( fscanf(arq,"%c",&lendo)!=EOF)
    {
        if(repeticao(arquivoA,i,lendo)==0)
        { 
            arquivoA[i]=lendo;
            i++;
        }
    }
    while(fscanf(arqB,"%c",&lendo)!=EOF)
    {
          if(repeticao(arquivoB,j,lendo)==0)
        { 
            arquivoB[j]=lendo;
            j++;
        }
    }

    for(k=0;k<i;k++)
        {
            for(l=0;l<j;l++)
            {
                if(arquivoA[k]==arquivoB[l])
                {
                    organizado[m]=arquivoA[k];
                    m++;
                    break;
                }
            }
        }

    fclose(arq);
    fclose (arqB);

    resposta = crescente(organizado,m);
    
    if(resposta==1)
    {
        j=0;
        while(m>j)
        {
            if(organizado[j]>='0' && organizado[j]<='9')
            {
                fprintf(arqC,"%c\n",organizado[j]);
            }
            j++;
        }
    }
    fclose (arqC);
    return resposta;

}
int crescente(char conteudo[],int quantidade)
{   
    int i,j;
    char temp;
    
    for(i=0;i<quantidade-1;i++)
    {
        for(j=0;j<quantidade-1;j++)
        {
            if(conteudo[j]>conteudo[j+1])
            {
                temp=conteudo[j+1];
                conteudo[j+1]=conteudo[j];
                conteudo[j]=temp;

             }  
         }
    }
    return 1;
}
int repeticao (char conteudo[],int i ,char lendo)
{
    int j;

    for(j=0;j< i;j++)
    {
            if(conteudo[j]==lendo)
            {
                return 1;
            }
        
    }
    return 0;
}