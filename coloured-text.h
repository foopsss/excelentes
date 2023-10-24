// Librería para imprimir texto coloreado.
// El propósito de esta librería es contener una serie de funciones que permitan 
// imprimir un texto pasado como argumento utilizando un color.

void red_text(char* text) {
  printf("\x1b[31m%s\n", text);
}

void green_text(char* text) {
  printf("\x1b[32m%s\n", text);
}

void blue_text(char* text) {
  printf("\x1b[34m%s\n", text);
}

void reset_colour() {
  printf("\x1b[0m");
}
