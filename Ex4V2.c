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
        
        printf("O arquivo esta vazio");
    }
    if(resposta==-1)
    {
      
        printf("O arquivo possui numeros mas nao estao em ordem crescente ");
    }
    if(resposta==-2)
    {
          printf("ERRO: nao foi possivel abrir o arquivo!!");
    }
    else
    {
        printf("O arquivo possui numeros e estao em ordem crescente");
    }
    return 0;
} 

int numeros (char nomeArq[])
{
    int lendoAtual,lendoAnte;
    FILE *arq;



    arq=fopen(nomeArq,"r");
    if(arq)
    {
        if(fscanf(arq,"%d",&lendoAnte)==EOF)
            {
                fclose(arq);
                return 0;
            }
            
        while( fscanf(arq,"%d",&lendoAtual)!=EOF)
            {            
                if(lendoAtual<lendoAnte)
                {
                    fclose (arq);
                    return -1;
                }
                lendoAnte=lendoAtual;
            }
     }
    else
        {
            return -2;
        }
    fclose(arq);

    return 1;
}
