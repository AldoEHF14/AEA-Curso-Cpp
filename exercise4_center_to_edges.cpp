#include <stdio.h>
#include <algorithm> // para std::min de C++

const int tam = 100000;
static int arr[tam];
static int arr2[tam];

using namespace std;

int main() {
    int n;
    // Leer el número de enteros
    scanf("%d", &n);
    getchar();

    int ini = ftell(stdin);  // Guardar posición inicial en stdin
    int mitad = n / 2;
    int fin = n / 2;         // Inicializar el tamaño restante
    int elem;

    // Leer y escribir el elemento central
    fseek(stdin, ini + mitad * 4, SEEK_SET);
    fread(&elem, 4, 1, stdin);
    fwrite(&elem, 4, 1, stdout);

    int i = 0;
    while (fin > 0) {
        int leer = min(tam, fin); // Leer hasta tam o el resto

        // Leer y revertir desde la izquierda
        fseek(stdin, ini + (mitad - i - leer) * 4, SEEK_SET);
        fread(&arr2[0], 4, leer, stdin);
        reverse(&arr2[0], &arr2[0] + leer);

        // Leer desde la derecha
        fseek(stdin, ini + (mitad + i + 1) * 4, SEEK_SET);
        fread(&arr[0], 4, leer, stdin);

        // Alternar entre elementos de izquierda y derecha
        int izq = 0, der = 0;
        while (izq < leer || der < leer) {
            if (der < leer) {
                fwrite(&arr2[der], 4, 1, stdout);
                der++;
            }
            if (izq < leer) {
                fwrite(&arr[izq], 4, 1, stdout);
                izq++;
            }
        }

        i += leer; // Incrementar el índice de desplazamiento
        fin -= leer; // Reducir el tamaño restante
    }

    return 0;
}