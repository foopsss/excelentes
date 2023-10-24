// Librería para imprimir texto coloreado.
// El propósito de esta librería es contener un método para permitir imprimir 
// un texto pasado como argumento utilizando un color.

// La idea sería también permitir que dicho texto pueda ser imprimido en cursiva
// o negritas si fuese deseado.

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
