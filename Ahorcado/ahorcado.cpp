#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

int main() {

    char frase[60], rep[100], temporal[100];
    char pal=-87;
    int longitud=0, i, j=0, inicial=0, acertado=0, temp=0, oportunidades=5;
    int repetido=0, gano=0;
   // int len;
    //char *algun_sitio = NULL;

    printf("\tJuego del ahorcado\n");
    printf("Introduce la palabra a adivinar: ");
    //fgets(frase, 60, stdin);
    scanf(" %[^\n]", frase);

    //len = strlen(frase);
    //algun_sitio = (char *) malloc( len * sizeof(char) );
    //strncpy(algun_sitio, frase, len - 1);
    //algun_sitio[len-1] = '\0';

    system("clear");

    do{
        temp=0;

        if(inicial == 0){
            for(i=0;i<strlen(frase);i++){
                if(frase[i] == ' '){
                    temporal[i] = ' ';
                    longitud++;
                }
                else {
                    temporal[i] = '_';
                    longitud++;
                }
            }
            inicial = 1;
            //temporal[longitud] = '\0'
        }
      else{
        for(i=0;i<strlen(rep);i++){
            if(rep[i] == pal){
                repetido = 1;
                break;
            }
            else{
                repetido = 0;
            }
        }
        if(repetido == 0){
            rep[j] = pal;
            j++;
            for(i=0;i<strlen(frase);i++){
                if(frase[i] == pal){
                    temporal[i] =pal;
                    acertado++;
                    temp=1;
                }
            }
        }
        if(repetido == 0){
            if(temp == 0 && pal!=-87){
                oportunidades = oportunidades - 1;
            }
            system("clear");

            for(i=0;i<strlen(temporal);i++){
                printf(" %c", temporal[i]);
            }

            printf("\n");

            if(strcmp(frase,temporal) == 0){
                gano = 1;
                break;
            }
            printf("\n");
            printf("Letras Acertadas: %d", acertado);
            printf("\n");
            printf("Oportunidades Restantes: %d", oportunidades);
            printf("\n");
        }
        else {
            printf("Ya se  ha introducido la '%c' en esta partida. ", pal);
        }
        if(oportunidades != 0){
            printf("Introduzca una letra: ");
            scanf(" %c", &pal);
            __fpurge(stdin);
        }
      }
    }while(oportunidades != 0);

    if(gano) {
        printf("\n\n");
        printf("Enorabuena, has ganado.");
    }
    else{
        printf("\n\n");
        printf("Has perdido");
    }

    printf("\n\n");



    return EXIT_SUCCESS;

}


