#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const int m = 500000; // Tamaño máximo del montículo
static int arr[m];

void push(int arr[], int& tam, int valor) {
   arr[tam] = valor;
   std::push_heap(&arr[0], &arr[++tam]); 
}

int top(int arr[]) {
   return arr[0]; 
}

void pop(int arr[], int& tam) {
   std::pop_heap(&arr[0], &arr[tam--]); 
}

void sort(int arr[], int tam) {
   std::sort_heap(&arr[0], &arr[tam]); 
}

int main() {
   FILE* arch = stdin;//fopen("archivo.txt", "r");
   if (!arch) {
      printf("Error al abrir el archivo.\n");
      return 1;
   }

   int n;
   fscanf(arch, "%d ", &n);
   //printf("%d",n);
   int ini = ftell(arch);
   int max = 0; 
   int bytes = n;
   int tam = 0;

   for (int i = 0; i < ceil(((double)n / (double)m)); i++) {
      fseek(arch, ini, SEEK_SET);
      int bytes_restantes = min(bytes, m);

      //printf("\nMAX: %d y bytes_restantes: %d\n", max, bytes_restantes);
      tam = 0;

      for (int j = 0; j < n; ++j) {
         int valor;
         //fscanf(arch, "%d ", &valor);
         fread(&valor, 4, 1, arch);
         if (tam < bytes_restantes && valor > max) {
            //printf("push: %d\n", valor);
            push(arr, tam, valor);
         } else if (valor > max && valor < top(arr)) {
            //printf("pop: %d - ", top(arr));
            pop(arr, tam);
            //printf("push: %d\n", valor);
            push(arr, tam, valor);
         }
      }

      max=top(arr);
      sort(arr, tam);
      //printf("Ordenado: ");
      //for (int k = 0; k < tam; k++) {
         //printf("%d ", arr[k]);
         fwrite(&arr[0], 4,tam, stdout);
      // }
      //printf("\n");
      bytes -= bytes_restantes;
    
    }

    fclose(arch);
    return 0;
}