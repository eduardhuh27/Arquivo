#include <stdio.h>

int copiardecres (char nomeArq[]);
int buscarmaior (char nomearq[],int *maior,int limite);

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

int copiardecres (char nomeArq[])
{

    int maior,limite=9999;
    FILE*arqB;
    

    //arq=fopen(nomeArq,"r");
    arqB=fopen("Novo.txt","w");

    if(!arqB)
    {
        fclose(arqB);
        return 0;
    }

    while(buscarmaior(nomeArq,&maior,limite)!=0)
    {
        
        fprintf(arqB,"%d\n",maior);
            
        limite=maior;
        
    }

    fclose (arqB);
    return 1;

}

int buscarmaior (char nomearq[],int *maior,int limite)
{   
    int i=0,temp;
    FILE *arq;
        arq=fopen(nomearq,"r");
    
        if(!arq)
        {
            return -1;
        }
        else
        {
            *maior=0;
                while(fscanf(arq,"%d",&temp)!=EOF)
                {
                 if((temp<limite) && (temp>*maior))
                 {
                    *maior=temp;
                    
                    i=1;
                 }    
                }
    fclose(arq);
    return i;
        }
}
