#include <stdio.h>

int unir (char nomeArq[],char nomeArqB[]);
int buscarMenor( char nomeArq[],char nomeArqB[],int *menor,int limite);

int main ()
{
    int resposta;
    char nomeArq[30];
    char nomeArqB[30];

    printf("Entre com nome do arquivo A:");
    scanf("%s",nomeArq);
    printf("Entre com nome do arquivo B:");
    scanf(" %s",nomeArqB);

    resposta=unir(nomeArq,nomeArqB);

    if(resposta==0)
    {
        printf("ERRO: nao foi possivel abrir o arquivo!!");

    }
}



int unir (char nomeArq[],char nomeArqB[])
{

    int menor,limite=-9999999;
    FILE*arqC;
    

    //arq=fopen(nomeArq,"r");
    arqC=fopen("ovo.txt","w");

    if(!arqC)
    {
        fclose(arqC);
        return 0;
    }

    while(buscarMenor(nomeArq,nomeArqB,&menor,limite)!=0)
    {
        
        fprintf(arqC,"%d\n",menor);
            
        limite=menor;
        
    }

    fclose (arqC);
    return 1;

}
int buscarMenor( char nomeArq[],char nomeArqB[],int *menor,int limite)
{   
    int i,j,achou=0;
    FILE *arq,*arqB;

    arq=fopen(nomeArq,"r");
    arqB=fopen(nomeArqB,"r");
    if(!arq || !arqB)
    {
        fclose(arq);
        fclose(arqB);
        return -1;
    }

    *menor=9999;
    while(fscanf(arq,"%d",&i)!=EOF)
    {
        if((i>limite) && i<*menor)
        {
            *menor=i;
            achou=1;
        }
    }
    while (fscanf(arqB,"%d",&j)!=EOF)
    {

         if((j>limite) && (achou== 0 || j<*menor))
        {
            *menor=j;
            achou=1;
        }
        
    }
    

        fclose(arq);
        fclose(arqB);
    
    return achou;
}