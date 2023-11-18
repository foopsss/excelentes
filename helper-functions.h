// Librería para almacenar funciones de usos varios.
// clrscr: sirve para limpiar el contenido de la pantalla.
// presskey: simula el comportamiento del ReadKey() de Pascal.

void clrscr() {
    #ifdef _WIN32
    system("cls");
    #endif

    #ifdef linux
    system("clear");
    #endif
}

void presskey() {
    // Limpiamos el buffer de entrada.
    getchar();

    // Simulamos un ReadKey().
    printf("Presione una tecla para salir.");
    getchar();
}
