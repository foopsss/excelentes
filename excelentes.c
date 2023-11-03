#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "helper-functions.h"

struct lugares {
    char* nombre;
    int votos;
};

int eleccion;

void MostrarOpciones() {
    printf("Elija uno de los destinos: \n");
    printf("0. Mar del Plata.\n");
    printf("1. Rio de Janeiro.\n");
    printf("2. Buzios.\n");
    printf("3. Cuba.\n");
    printf("4. Santo Domingo.\n");
    printf("5. SALIR.\n");
    printf("\n");
    printf("Introduzca su elección: ");
    scanf("%d", &eleccion);
    
    // Chequeamos que los valores se encuentren dentro del rango aceptable.
    // De lo contrario, se considera un error.
    if (eleccion > 5 || eleccion < 0) {
	clrscr();
	printf("Usted seleccionó una opción incorrecta.\n");
	printf("Por favor, seleccione una opción correcta.\n");
	printf("\n");
	MostrarOpciones();
    }
}

void main() {
    struct lugares destinos[5];
    struct lugares resguardo;
    int i, cantidadvotos;
    bool bandera = false;
    
    // Cargamos los nombres de las ubicaciones en nuestro arreglo.
    // También ponemos a cero el resguardo que vamos a utilizar más adelante.
    destinos[0].nombre = "Mar del Plata";
    destinos[1].nombre = "Rio de Janeiro";
    destinos[2].nombre = "Buzios";
    destinos[3].nombre = "Cuba";
    destinos[4].nombre = "Santo Domingo";
    resguardo.votos = 0;
    
    for (i = 0; i < 5; i++) {
	destinos[i].votos = 0;
    }

    // Le ofrecemos a los usuarios la posibilidad de votar.
    MostrarOpciones();
    
    while (eleccion != 5) {
	destinos[eleccion].votos = destinos[eleccion].votos + 1;
	cantidadvotos = cantidadvotos + 1;
	clrscr();
	MostrarOpciones();
    }

    // Con la votación consumada, reordenamos el arreglo en función de los
    // lugares más votados, de mayor a menor.
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

    // Mostramos el ranking luego de ordenar el arreglo con los votos.
    if (cantidadvotos > 0) {
	clrscr();
	printf("Ranking de los sitios más votados: \n");
	printf("\n");
	for (i = 0; i < 5; i++) {
	    printf("%s: %d\n", destinos[i].nombre, destinos[i].votos);
	}
    }
}
