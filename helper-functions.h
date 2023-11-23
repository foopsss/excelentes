// Librería para almacenar funciones de usos varios.

// clrscr: sirve para limpiar el contenido de la pantalla.
void clrscr() {
    #ifdef _WIN32
    system("cls");
    #endif

    #ifdef linux
    system("clear");
    #endif
}

// MostrarOpciones: muestra el menú de opciones a elegir para el usuario.
int eleccion;

void MostrarOpciones() {
    printf("Elija una de las opciones: \n");
    printf("0. Mar del Plata.\n");
    printf("1. Rio de Janeiro.\n");
    printf("2. Buzios.\n");
    printf("3. Cuba.\n");
    printf("4. Santo Domingo.\n");
    printf("5. SALIR.\n");
    printf("\n");
    printf("Introduzca su eleccion: ");
    scanf("%d", &eleccion);
    
    // Chequeamos que los valores se encuentren dentro del rango aceptable.
    if (eleccion > 5 || eleccion < 0) {
	clrscr();
	printf("Usted selecciono una opcion incorrecta.\n");
	printf("Por favor, seleccione una opcion correcta.\n");
	printf("\n");
	MostrarOpciones();
    }
}

// presskey: simula el comportamiento del ReadKey() de Pascal.
void presskey() {
    // Limpiamos el buffer de entrada.
    getchar();

    // Simulamos un ReadKey().
    printf("Presione una tecla para salir.");
    getchar();
}
