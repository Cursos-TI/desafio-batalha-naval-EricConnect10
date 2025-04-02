#include <stdio.h>

// Desafio Batalha Naval 

# define tamanho 10 



void exibicao_tabuleiro (int tabuleiro [tamanho][tamanho]) { 

    printf("    A B C D E F G H I J\n"); 

    for (int x = 0; x < tamanho; x ++) { 

        printf("%d: ", x);  

        for (int y = 0; y < tamanho; y ++) {

            printf(" %d", tabuleiro[x][y]);

        }

        printf("\n");

    }

}

void navio_horizontal (int tabuleiro[tamanho][tamanho], int linha, int coluna) {  

    if(coluna + 2 < tamanho) {  

        for (int x = 0; x < 3; x ++) { 

            if (tabuleiro[linha][coluna + x] == 3){

                printf("O navio da horixontal não pode ser posicionado em (%d, %d) por ja estar ocupado por um outro !\n", linha, coluna);

                return;

            }

        }

    for (int x = 0; x < 3; x ++) { 

        tabuleiro[linha][coluna + x] = 3; 

        }

    } else { 

        printf("O navio da horixontal não pode ser posicionado aqui por ultrapassar o limite do tabuleiro !\n");

        return;

    }

}

void navio_vertical (int tabuleiro[tamanho][tamanho], int linha, int coluna) { 

    if (linha + 2 < tamanho) { 

        for (int y = 0; y < 3; y ++) {

            if (tabuleiro[linha + y][coluna] == 3){

                printf("O navio da vertical não pode ser posicionado em (%d, %d) por ja estar ocupado por um outro !\n", linha, coluna);

            return;

            }

        }    

    for (int y = 0; y < 3; y ++) { 

        tabuleiro[linha + y][coluna] = 3;  
        }

    } else { 

        printf("O navio da vertical não pode ser posicionado aqui por ultrapassar o limite do tabuleiro !\n");

    return;

    }

}

void navio_diagonal1 (int tabuleiro[tamanho][tamanho], int linha, int coluna) {  
    if ((linha + 2 < tamanho) && (coluna + 2 < tamanho)) { 
        for (int x = 0, y = 0; x < 3 && y < 3; x ++, y ++) { 

            if (tabuleiro[linha + y][coluna + x] == 3){

                printf("O navio da diagonal 1 não pode ser posicionado em (%d, %d) por ja estar ocupado por um outro !\n", linha, coluna);

            return;

            }

        }    

    for (int x = 0, y = 0; x < 3 && y < 3; x ++, y ++) { 

        tabuleiro[linha + y][coluna + x] = 3; 

        }

    } else {  

        printf("O navio da diagonal 1 não pode ser posicionado aqui por ultrapassar o limite do tabuleiro !\n");

    return;

    }

}

void navio_diagonal2 (int tabuleiro[tamanho][tamanho], int linha, int coluna) {  
    if ((linha + 2 < tamanho) && (coluna - 2 >= 0)) { 

        for (int x = 0, y = 0; x < 3 && y < 3; x ++, y ++) {  
            if (tabuleiro[linha + y][coluna - x] == 3){

                printf("O navio da diagonal 2 não pode ser posicionado em (%d, %d) por ja estar ocupado por um outro !\n", linha, coluna);

            return;

            }

        }    

    for (int x = 0, y = 0; x < 3 && y < 3; x ++, y ++) { 

        tabuleiro[linha + y][coluna - x] = 3; 
        }

    } else {  

        printf("O navio da diagonal 2 não pode ser posicionado aqui por ultrapassar o limite do tabuleiro !\n");

    return;

    }

}

void habilidade_cone(int tabuleiro[tamanho][tamanho], int origemi, int origemj) {  
    if ((origemi + 2 >= tamanho) || (origemj + 2 >= tamanho) || (origemj - 2 < 0)) { 
        printf("A habilidade cone ultrapassa os limites do tabuleiro!\n");

        return;

    }

   

    for (int i = 0; i < 3; i++) { 

        for (int j = -i; j <= i; j++) { 

            int ei = origemi + i;  

            int ej = origemj + j;  

            if (ei < tamanho && ej >= 0 && ej < tamanho) { 

                if (tabuleiro[ei][ej] == 3) {   

                    tabuleiro[ei][ej] = 0;

                } else {

                    tabuleiro[ei][ej] = 1; 

                }

            }

        }

    }

}

void habilidade_cruz(int tabuleiro[tamanho][tamanho], int origemi, int origemj) {  

    if ((origemi + 1 >= tamanho) || (origemi - 1 < 0) || (origemj + 2 >= tamanho) || (origemj - 2 < 0)) {  
        printf("A habilidade cruz ultrapassa os limites do tabuleiro!\n");

        return;  //   

    }



    for (int i = -1; i < 2; i++) {  

        int ei = origemi + i;  

        if (ei >= 0 && ei < tamanho) {  

            if (tabuleiro[ei][origemj] == 3) {   

                tabuleiro[ei][origemj] = 0;

            } else {

                tabuleiro[ei][origemj] = 1; 

            }

        }

    }



    for (int j = -2; j <= 2; j++) {  

        int ej = origemj + j;   

        if (ej >= 0 && ej < tamanho) {  

            if (tabuleiro[origemi][ej] == 3) {   

                tabuleiro[origemi][ej] = 0;

            } else {

                tabuleiro[origemi][ej] = 1;   
            }

        }

    }

}

void habilidade_octaedro(int tabuleiro[tamanho][tamanho], int origemi, int origemj) {   

    if ((origemi + 1 >= tamanho) || (origemi - 1 < 0) || (origemj + 1 >= tamanho) || (origemj - 1 < 0)) {  

        printf("A habilidade octaedro ultrapassa os limites do tabuleiro!\n");

        return;  

    }



    for (int i = -1; i < 2; i ++) {  

        int ei = origemi + i;

        if (ei >= 0 && ei < tamanho) {

            if (tabuleiro[ei][origemj] == 3) {  
                tabuleiro[ei][origemj] = 0;

            } else {

                tabuleiro[ei][origemj] = 1; 

            }

        }

    }

    for (int j = -1; j < 2; j ++) { 
        int ej = origemj + j;

        if (ej >= 0 && ej < tamanho) {

            if (tabuleiro[origemi][ej] == 3) {  

                tabuleiro[origemi][ej] = 0;

            } else {

                tabuleiro[origemi][ej] = 3;  

            }

        }

    }

}



int main() {



    int tabuleiro[tamanho][tamanho] = {0};   


    navio_horizontal(tabuleiro, 2, 2); 

    navio_vertical(tabuleiro, 6, 6);   

    navio_diagonal1(tabuleiro, 1, 7);   

    navio_diagonal2(tabuleiro, 4, 3);  

    habilidade_cone(tabuleiro, 7, 2);
    habilidade_cruz(tabuleiro, 1, 2);

    habilidade_octaedro(tabuleiro, 7, 6);
    exibicao_tabuleiro(tabuleiro);



    return 0;

}
