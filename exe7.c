#include<stdio.h>

void mostra(char jg[][3]){
    //pq eu preciso informe as colunas?
    // tem modo de fazer com for?
printf(" %c | %c | %c \n", jg[0][0], jg[0][1], jg[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", jg[1][0], jg[1][1], jg[1][2]);
    printf("---|---|---\n"); 
    printf(" %c | %c | %c \n", jg[2][0], jg[2][1], jg[2][2]);
}

int pode(char jg[][3], int i, int j){
    int res = 0;
    if(jg[i][j] != ' '){
        res = 1;
    }
    return res;
}

int ganhar(char jg[][3]){
    
    for(int i = 0; i < 3; i ++){
        if((jg[i][0]) == (jg[i][1]) && jg[i][0] == (jg[i][2]) && (jg[i][0]) != ' '){
            if(jg[i][0] == 'x'){
                printf("o x ganhou\n");
            }else{
                printf("o o ganhou\n");
            }   
            return 1;
        } 
    }

    for(int j = 0; j < 3; j ++){
        if(jg[0][j] == jg[1][j] && jg[0][j] == jg[2][j] && jg[0][j] != ' '){
            if(jg[0][j] == 'x'){
                printf("o x ganhou\n");
            }else{
                printf("o o ganhou\n");
            }
            return 1;
    }
    }

    if(jg[0][0] == jg[1][1] && jg[0][0] == jg[2][2] && jg[0][0] != ' '){
        if(jg[0][0] == 'x'){
                printf("o x ganhou\n");
            }else{
                printf("o o ganhou\n");
            }
            return 1;
    }

    if(jg[0][2] == jg[1][1] && jg[0][2] == jg[2][0] && jg[1][1] != ' '){
        if(jg[1][1] == 'x'){
                printf("o x ganhou\n");
            }else{
                printf("o o ganhou\n");
            }
            return 1;
    }

    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            if(jg[i][j] == ' '){
                return 0;
            }
        }
    }

    printf("O jogo empatou\n");    
    return 1;
}




int main(){
    char jg[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    //com o {0} ficava estranho no começo

    int conf = 0;

    mostra(jg);

    do{
        int i = 0, j = 0;
        //ainda pode ser melhorado
       
        printf("Informe onde voce quer marcar o tabuleiro, linha e coluna\n");
        scanf("%d %d", &i, &j);
        
        if(i >= 0 && i <= 2 && j >= 0 && j <= 2){
            if(pode(jg, i, j) == 0){
                printf("Coloque x ou o\n");
                scanf(" %c", &jg[i][j]);
                mostra(jg);
            }else{
                printf("posicao ocupada\n");
            }
        }else{
            printf("posicao invalida\n");
        }

        conf = ganhar(jg);

    }while(conf == 0);

    return 0;
}