#include <stdio.h>

int main(){
    // Inicialização de Arrays de linhas e colunas
    char *linhas[10] = {"01","02","03","04","05","06","07","08","09","10"};
    char *colunas[10] = {"A","B","C","D","E","F","G","H","I","J"};
    // Declaração da Matriz do Tabuleiro
    int tabuleiro[10][10];


    // 01. Inicialização em massa da matriz de tabuleiro
    // Valor 0 para "Agua"
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }        
    }

    //02. Posicionamento dos Navios

    /*
    Tipo de Navio	Tamanho	Quantidade
    Porta-Aviões	5       1
    Encouraçado	    4	    1
    Cruzador	    3	    2
    Submarino	    2	    1
 
    */

    // Posicionamento do Porta-Aviões (Vertical)
    // Linha 03 até 07 - Coluna E

    for (int i = 2; i < 7; i++)
    {
        tabuleiro[i][4] = 3;
    }

    // Posicionamento do Encouraçado (Horizontal)
    // Linha 08 - Coluna C até F

    for (int i = 2; i < 6; i++)
    {
        tabuleiro[][i] = 3;
    }
    
    // 03. Impressão do Tabuleiro

    printf("------ BATALHA NAVAL ------\n\n");

    printf("   ");

    // Impressão do cabeçalho das Colunas
    for (int i = 0; i < 10; i++)
    {
        printf("%s ", colunas[i]);
    }
    // Quebra de linha pós impressão dos cabeçalhos
    printf("\n");

    // Impressão do Tabuleiro com as peças escolhidas
    for (int i = 0; i < 10; i++)
    {   
        printf("%s ", linhas[i]);

        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    
    
    





    return 0;
}
