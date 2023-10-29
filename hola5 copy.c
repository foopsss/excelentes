#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct lugares {
    char* nombre;
    int votos;
};

int eleccion;




void clrscr() {
    #ifdef _WIN32
    system("cls");
    #endif

    #ifdef linux
    system("clear");
    #endif
}

void MostrarOpciones() {
    
    while (eleccion>7 || eleccion<0)
    {
        printf("Elija uno de los destinos: \n");
        printf("1. Mar del Plata\n");
        printf("2. Rio de Janeiro\n");
        printf("3. Buzios\n");
        printf("4. Cuba\n");
        printf("5. Santo Domingo\n");
        printf("6. SALIR\n");
        printf("Introduzca su eleccion: ");
        scanf("%d", &eleccion);
        while (getchar() != '\n'); // Consumir el carácter de nueva línea
        if (eleccion>7 || eleccion<1)
        {
            clrscr();
            
            printf("Error, el numero ingresado no coincide con el menu.");
            eleccion = -1;
            
        }

    }
}


void main() {
    struct lugares destinos[5];
    bool bandera;
    bool bandera2;
    int i; int j;
    struct lugares x; 
    int value = 6;
    bandera = false;
    bandera2 = true;
    printf("hola");
    eleccion = -1;
    j = 0;

    // .
    destinos[0].nombre = "Mar del Plata";
    destinos[1].nombre = "Rio de Janeiro";
    destinos[2].nombre = "Buzios";
    destinos[3].nombre = "Cuba";
    destinos[4].nombre = "Santo Domingo";

    for (i = 0; i < 5; i++) {
    destinos[i].votos = 0;
    }



    while (eleccion != value) {
        eleccion = -1;
        MostrarOpciones();
        if (eleccion != 6)
        {
            destinos[eleccion-1].votos = destinos[eleccion-1].votos + 1;
            bandera2 = false;
        }
        clrscr();
        
    }
    printf("sale");
    getchar();
    if ( !bandera2 ) 
    {
        printf("Hay, al menos, UN voto.\n\n");
        printf("Arreglo sin ordenar:\n");
        for (j = 0; j < 5; j++)
        {
            printf("%d)En la provincia:%s; Votos:%d\n", j,destinos[j].nombre, destinos[j].votos);
        }
        printf("\n");

        while (bandera == false)
        {
            bandera = true;
            for (j = 0; j < 4; j++)
            {
                if (destinos[j].votos < destinos[j+1].votos)
                {
                    x = destinos[j];
                    destinos[j] = destinos[j+1];
                    destinos[j+1] = x;
                    bandera = false;
                }

            }
        }
        // Ordenar destinos por la cantidad de votos (orden descendente)

        printf("Arreglo ordenado:\n");
        for (j = 0; j < 5; j++)
        {
            printf("%d)En la provincia:%s; Votos:%d\n", j,destinos[j].nombre, destinos[j].votos);
        }
        getchar();
    }
    else
    {
        printf("NADIE HA VOTADO, ELECCIONES CANCELADAS.");
        getchar();
    }
}