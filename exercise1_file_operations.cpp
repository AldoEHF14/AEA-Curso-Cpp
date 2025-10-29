#include <iostream>
#include <algorithm>

using namespace std;

const int columnas = 16;
const int filas = 1750000;
static unsigned matriz1[filas][columnas] = {0};
static unsigned matriz2[columnas][filas] = {0};

int main() {
    unsigned n, t;
    unsigned a, c, x;
    unsigned arreglo[16] = {0};
    cin >> a >> c >> x >> n >> t;

    // Inicializa matriz2
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < n; j++) {
            matriz2[i][j] = 0;
            // cout<<matriz2[i][j];
        }
    }

    // Rellenar matrices alternadamente
    for (int k = 0; k < t; k++) {
        if (k % 2 == 0) { // matriz1[n][16]
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 16; j++) {
                    matriz1[i][j] += x;
                    x = a * x + c;
                    // cout<<matriz1[i][j];
                }
            }
        } else { // matriz2[16][n]
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < n; j++) {
                    matriz2[i][j] += x;
                    x = a * x + c;
                    // cout<<matriz2[i][j];
                }
            }
        }
    }

    // Sumar ambas matrices
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 16; ++j) {
            matriz1[i][j] += matriz2[j][i];
            // cout<<matriz1[i][j];
        }
    }

    // Ordenar cada fila
    for (int i = 0; i < n; ++i) {
        sort(&matriz1[i][0], &matriz1[i][16]);
    }

    // Sumar columnas
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 16; ++j) {
            arreglo[j] += matriz1[i][j];
            // cout<<arreglo[j];
        }
    }

    // Imprimir resultado
    for (int i = 0; i < 16; i++) {
        cout << arreglo[i] << " ";
    }

    cout << endl;
    return 0;
}
