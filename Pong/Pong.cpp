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
void leercamp (char campo[V][H]);
void gameloop (char campo[V][H], int pelX, int pelY, int inijug, int finjug, int iniIA, int finIA, int modX, int modY, int modIA);
void draw (campo[V][H]);
void input (char campo[V][H], int *pelX, int *pelY, int *inijug, int *finjug, int *iniIA, int *finIA, int *modX, int *modY, int *modIA, int *gol);

int main() {

    int pelX, pelY, inijug, finjug, iniIA, finIA; //posicion 
    int modX, modY, medIA;
    char campo[V][H];


    //posicion
    pelX = 37;
    pelY = 10;

    inijug = 8;
    finjug = 12;

    iniIA = 8;
    finIA = 12;

    //modificacion

    modX = -1;
    modY = -1;
    modIA = -1;

    inicio(campo, pelX, pelY, inijug, finjug, iniIA, finIA);
    gameloop(campo, pelX, pelY, inijug, finjug, iniIA, finIA, modX, modY, modIA);
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
        for (int j = 0; j <= H; j++){
            if (i == 0 || i == V-1){
                campo[i][j] = '-';
            }else if (j == 0 || j == H){
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

void leercamp (char campo[V][H]){
    for (int i = 0; i < V; i++){
        for (int j = 0; j < H; j++){
            printf("%c", campo[i][j]);
        }
        printf("\n");
    }
}

void gameloop (char campo[V][H], int pelX, int pelY, int inijug, int finjug, int iniIA, int finIA, int modX, int modY, int modIA){

    int gol = 0;

    do{
      draw (campo);//dibujar en pantalla
      input (campo, &pelX, &pelY, &inijug, &finjug, &iniIA, &finIA, &modX, &modY, &modIA, &gol);//modificar la posicion
      update (); // actualirzar la matriz campo
      sleep (10);
    }while(gol == 0);
}

void draw (char campo[V][H]){
    system ("clear");
    leercamp (campo);
}

void input (char campo[V][H], int *pelX, int *pelY, int *inijug, int *finjug, int *iniIA, int *finIA, int *modX, int *modY, int *modIA, int *gol){
    //verificacion
    if (*pelY == 1 || *pelY == V-2){
        *modY *= -1;
    }

    if (*pelX == 1 || *pelY == H-2){
        *gol = 1;
    }

    if (*pelX == 4){
        for (int i = (*inijug); i <= (*finjug); i++){
            if (i == (*PelY)){
                *modX *= -1;
            }
        }
    }

    if (*pelX == H-5){
        for (int i = (*iniIA); i <= (*finIA); i++){
            if (i == (*pelY)){
                *mod *= -1;
            }
        }
    }
    //modificacion

}
