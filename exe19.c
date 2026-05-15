#include<stdio.h>

void mostrar(int torre[][4]){
    for(int i = 0; i < 3; i ++){
        if(i == 0){
                printf("A: ");
            }else if(i == 1){
                printf("B: ");
            }else{
                printf("C: ");
            }
        for(int j = 0; j < 4; j ++){
            printf("%d ", torre[i][j]);
        }
        printf("\n");
    }
}



int cont(int a, int torre[][4]){
    int qnts = 0;
    for(int i = 0; i < 4; i ++){
        if(torre[a][i] != 0){
            qnts ++;
        }else{
            break;
        }
    }

    return qnts;
}

int fim(int torre[][4]){
    int rec = 0;
    if(cont(2, torre) == 4){
        rec = 1;
    }
    return rec;
}

int pode(int a, int d, int torre[][4]){
    int pd = 0;
    
    if(a < 0 || a > 2 || d < 0 || d > 2){
        return pd;
    }else if(a == d){
        return pd;
    }

    int ta = cont(a, torre) - 1;
    int td = cont(d, torre) - 1;

    if(cont(d, torre) == 0){
        pd = 1;
        return pd;
    }

    if(torre[a][ta] > torre[d][td]){
        return pd;
    }

    pd = 1;

    return pd;
}

void move(int a, int d, int torre[][4]){
    int ta = cont(a, torre) - 1;
    int pd = cont(d, torre);

    int temp = torre[a][ta];

    torre[a][ta] = 0;

    torre[d][pd] = temp;
}


int main(){

    int torre[3][4] ={
        {4, 3, 2, 1},
        {0},{0}
    };

    mostrar(torre);

    do{
        int a = 0, d = 0;
        printf("Para mover a peca, informe onde ela esta e para onde vai(A = 0; B = 1; C = 2)\n");
        scanf("%d %d", &a, &d);

        if(pode(a, d, torre) == 1){
            move(a, d, torre);
        }else{
            printf("Nao foi possivel realizar o movimento\n");
        }

        mostrar(torre);

    }while(fim(torre) == 0);

    printf("Voce ganhou, parabens!\n");

    return 0;
}