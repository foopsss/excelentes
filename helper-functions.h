// Librería para almacenar funciones de usos varios.
// Actualmente, la única función disponible es clrscr(), que contiene dos
// condicionales para controlar el uso de métodos de limpieza de pantalla según
// el sistema operativo que se use.

void clrscr() {
    #ifdef _WIN32
    system("cls");
    #endif

    #ifdef linux
    system("clear");
    #endif
}
