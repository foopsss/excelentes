#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "helper-functions.h"

struct lugares {
    char* nombre;
    int votos;
};

int main() {
    struct lugares destinos[5];
    struct lugares resguardo;
    int i, cantidadvotos;
    bool bandera = false;
    
    cantidadvotos = 0;

    destinos[0].nombre = "Mar del Plata";
    destinos[1].nombre = "Rio de Janeiro";
    destinos[2].nombre = "Buzios";
    destinos[3].nombre = "Cuba";
    destinos[4].nombre = "Santo Domingo";
    resguardo.votos = 0;
    
    for (i = 0; i < 5; i++) {
	destinos[i].votos = 0;
    }

    MostrarOpciones();
    
    while (eleccion != 5) {
	destinos[eleccion].votos = destinos[eleccion].votos + 1;
	cantidadvotos = cantidadvotos + 1;
	clrscr();
	MostrarOpciones();
    }

    // Reordenamos el arreglo en función de los lugares más votados de mayor a menor.
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

    if (cantidadvotos > 0) {
	clrscr();

	printf("Ranking de los sitios mas votados: \n");
	printf("\n");
	for (i = 0; i < 5; i++) {
	    printf("%s: %d\n", destinos[i].nombre, destinos[i].votos);
	}

	printf("\n");
	presskey();
    }

    return 0;
}
