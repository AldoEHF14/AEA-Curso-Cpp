#include <iostream>
#include <string>

using namespace std;
const int MAX_VALORES = 11881376 * 2; // Doble del tamaño original para incluir mayúsculas y minúsculas
static bool conjunto[MAX_VALORES] = {}; // Arreglo para marcar valores únicos

// Función para convertir un solo carácter en un número único
int h(char letra) {
    if (letra >= 'a' && letra <= 'z') {
        return letra - 'a'; // Minúsculas: 'a' es 0, 'z' es 25
    }
    if (letra >= 'A' && letra <= 'Z') {
        return letra - 'A'; // Mayúsculas: 'A' es 0, 'Z' es 25
    }
    return -1; // Retorna -1 si el carácter no es una letra válida
}

// Función para convertir una cadena de 5 letras en un número único
int h(const char cad[]) {
    for (int i = 0; i < 5; i++) {
        if (h(cad[i]) == -1) {
            return -1; // Retorna -1 si algún carácter no es válido
        }
    }
    //cout<<"h:"<<cad<<endl;
    int valor_base = ((h(cad[0]) * 26 * 26 * 26 * 26) +
                      (h(cad[1]) * 26 * 26 * 26) +
                      (h(cad[2]) * 26 * 26) +
                      (h(cad[3]) * 26) +
                      (h(cad[4]) * 1));

    // Si la primera letra es mayúscula, ajusta el valor al segundo rango
    if (cad[0] >= 'A' && cad[0] <= 'Z') {
        valor_base += 11881376; // Desplaza las mayúsculas al rango adecuado
    }

    return valor_base;
}

int main() {
    int contador = 0;
    int n;  // Número de cadenas que el usuario desea procesar
    char cadena[7]; // Cadena de 5 caracteres + nulo

    // Leer el número de cadenas a procesar
    cin >> n;

    // Procesar cada cadena
    for (int i = 0; i < n; i++) {
        cin >> cadena;

        // Calcular el valor de la función h para la cadena completa
        int valor = h(cadena);

        //cout<<valor<<endl;
        // Si el valor no está marcado en el conjunto, márcalo como presente
        if (!conjunto[valor]) {
            conjunto[valor] = true;
            contador++; // Incrementa el contador de elementos no repetidos
        }
    }

    // Mostrar el contador de elementos no repetidos
    cout << contador << endl;

    return 0;
}