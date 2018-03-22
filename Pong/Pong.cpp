#include <stdlib.h>
#include <stdio.h>

#define PAUSE() printf("Pulsa intro para continuar...");getchar();

#define V 21
#define H 75

void inicio (char campo[V][H], int pelX, int pelY, int inijug, int finjug, int iniIA, int finIA);
void borde (char campo[V][H]);
void raqjug (char campo[V][H], int inijug, int finjug);
void raqIA (char campo[V][H], int iniIA, int finIA);
void pel (char campo[V][H], int pelX, int pelY);


int main() {

    int pelX, pelY, inijug, finjug, iniIA, finIA;
    char campo[V][H];

    pelX = 37;
    pelY = 10;

    inijug = 8;
    finjug = 12;

    iniIA = 8;
    finIA = 12;

    inicio(campo, pelX, pelY, inijug, finjug, iniIA, finIA);
    //system("PAUSE");
    //scanf("");
    //printf("Pulsa intro para continuar...");getchar();
    PAUSE();
    return EXIT_SUCCESS;

}

void inicio (char campo[V][H], int pelX, int pelY, int inijug, int finjug, int iniIA, int finIA){
    borde (campo);
    raqjug (campo, inijug, finjug);
    raqIA (campo, iniIA, finIA);
    pel (campo, pelX, pelY);
}

void borde (char campo[V][H]){
    for (int i = 0; i < V; i++){
        for (int j = 0; j < H; j++){
            if (i == 0 || i == V-1){
                campo[i][j] = '-';
            }else if (j == 0 || j == H-1){
                campo[i][j] = '|';
            }
            else{
                campo[i][j] = ' ';
            }
        }
    }
}

void raqjug (char campo[V][H], int inijug, int finjug){
    for (int i = inijug; i <= finjug; i++){
        for (int j = 2; j <=3; j++){
            campo[i][j] = 'x';
        }
    }
}

void raqIA (char campo[V][H], int iniIA, int finIA){
    for (int i = iniIA; i <= finIA; i++){
        for (int j = H-4;j  <= H-3; j++){
            campo[i][j] = 'x';
        }
    }
}

void pel (char campo[V][H], int pelX, int pelY){
    campo[pelY][pelY] = '0';
}
