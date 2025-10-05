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


    // 02. Posicionamento das peças:
    /*
    
    Navio Vertical     = Numero do tabuleiro -> 3
    Cone               = Numero do tabuleiro -> 4
    Cruz               = Numero do tabuleiro -> 5
    Octaedro           = Numero do tabuleiro -> 6
    Navio Horizontal   = Numero do tabuleiro -> 7
    Navio Diagonanal 1 = Numero do tabuleiro -> 8
    Navio Diagonanal 2 = Numero do tabuleiro -> 9


    
    */
    for (int i = 4; i < 9; i++)
    {
        tabuleiro[i][0] = 3; // Linha 5 (i = 4) até Linha 9 (i = 8) na coluna A (j = 0)
    }


    // Navio Horizontal
    for (int j = 2; j < 6; j++) 
    {
        tabuleiro[4][j] = 7; // Linha 5 (i = 4) e Coluna de C até a F
    }

    // Cone
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j >= 2-i && j <= 2+i) // Se i for 1, j vai ser entre>= 2 - 1  e <= 2 + 1
            {                         // de j = 1 a j = 3 
                tabuleiro[i][j] = 4;
            }
        }    
    }

    // Cruz
    for (int i = 7; i <= 9; i++)
    {
        for (int j = 5; j <= 9; j++)
        {
            if (i == 8 || j == 7) // Sempre que for a linha 8 ou a coluna 7 (H)
            {
                tabuleiro[i][j] = 5;
            }      
        }    
    }

    // Diagonal Principal
    for (int i = 3; i < 7; i++)
    {
        // j = i + 3 
        tabuleiro[i][i+3] = 8; // Ex.: i = 6, então j = 6 + 3 (9)       
    }

    // Diagonal Secundária
    for (int i = 5; i < 9; i++)
    {
        // j = 9 - i
        tabuleiro[i][9-i] = 9; // Ex.: i = 5, então j = 9 - 5 (4)
    }
    

    // Octaedro

    int raio_max = 1;
    int centro_j = 7;
    int centro_i = 1;

    /*
    i = 1 (centro_i) - 1 (raio_max) (0) até i = 1 + 1 (2)
    j = 7 (centro_j) - 1 (raio_max) (6 ou G)  até j = 7 + 1 (8 ou J)     
    */ 
    for (int i = centro_i - raio_max; i <= centro_i + raio_max; i++)
    {
        for (int j = centro_j - raio_max; j <= centro_j + raio_max; j++)
        {
            if (i == 1 || j == 7) // Sempre que for a linha 2 (i = 1) ou a coluna 7 (H)
            {
                tabuleiro[i][j] = 6;
            }       
            
        }    
    }

    // 02. Impressão do Tabuleiro

    printf("------ BATALHA NAVAL ------\n\n");

    printf("    ");

    // Impressão do cabeçalho das Colunas
    for (int i = 0; i < 10; i++)
    {
        printf("%s  ", colunas[i]);
    }
    // Quebra de linha pós impressão dos cabeçalhos
    printf("\n");

    // Impressão do Tabuleiro com as peças escolhidas
    for (int i = 0; i < 10; i++)
    {   
        printf("%s  ", linhas[i]);

        for (int j = 0; j < 10; j++)
        {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
