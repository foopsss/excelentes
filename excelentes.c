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
    printf("Elija uno de los destinos: \n");
    printf("0. Mar del Plata.\n");
    printf("1. Rio de Janeiro.\n");
    printf("2. Buzios.\n");
    printf("3. Cuba.\n");
    printf("4. Santo Domingo.\n");
    printf("5. SALIR.\n");
    printf("Introduzca su elección: ");
    scanf("%d", &eleccion);
    
    if (eleccion > 5) {
	printf("¡Operación no válida!\n");
	eleccion = 0;
	MostrarOpciones();
    }
}

void main() {
    struct lugares destinos[5];
    struct lugares resguardo;
    int i;
    int retorno = 5;
    bool bandera = false;
    
    // .
    destinos[0].nombre = "Mar del Plata";
    destinos[1].nombre = "Rio de Janeiro";
    destinos[2].nombre = "Buzios";
    destinos[3].nombre = "Cuba";
    destinos[4].nombre = "Santo Domingo";
    resguardo.votos = 0;
    
    for (i = 0; i < 5; i++) {
	destinos[i].votos = 0;
    }

    // .
    MostrarOpciones();
    
    while (eleccion != retorno) {
	destinos[eleccion].votos = destinos[eleccion].votos + 1;
	clrscr();
	MostrarOpciones();
    }

    while (!bandera) {
	bandera = true;
	
	for (i = 0; i < 4; i++) {
	    if (destinos[i].votos < destinos[i + 1].votos) {
		resguardo = destinos[i];
		destinos[i] = destinos[i + 1];
		destinos[i + 1] = resguardo;
		bandera = false;
	    }
	}
    }

    printf("Ranking de los sitios más votados: \n");
    for (i = 0; i < 5; i++) {
	printf("%s\n", destinos[i].nombre);
	printf("%d\n", destinos[i].votos);
    }
}
