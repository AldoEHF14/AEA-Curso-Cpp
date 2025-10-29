#include <iostream> 
#include <stdio.h> 

const int D = 100000;// 1<=D<=100000
const int MAX_ARCHIVOS = 50;
const int MAX_BLOQUES = 100;
static int bloque[MAX_BLOQUES];//1<=N<=50
static int bloques[MAX_ARCHIVOS][MAX_BLOQUES];// 1<=N<=50 y 1<=bloques<=100
static int buffer[D];//1<=D<=100000
using namespace std;

int main(){ 
 
    int D,B,N;//N: Numero de archivos 
    int elem,ini=0; 
    scanf("%d %d %d",&D,&B,&N);
    //printf("%d %d %d\n",D,B,N);         
    int i=0,k=0; 
 
    while (i<N) {//i<N -> con fread y fwrite 
       int numBloques;
        scanf("%d ",&bloque[i]);
        //printf("%d ",bloque[i]);
        numBloques = (bloque[i] + B-1) / B;
        //printf("bloques: %d",numBloques);
        //Leer cuantos bloques requiere el archivo
        for (int j = 0; j < numBloques; j++) {
            //int bloq;
            scanf("%d",&bloques[i][j]);
            //printf("%d ",bloques[i][j]);
            }
        //printf("\n");
        //k++;
        i++; 
    } 
    ini = ftell(stdin);  // Guardar posición inicial en stdin
    //printf("%d",ini);

    i = 0;
    while (i < N) {
        int bytes_restantes = bloque[i];
        int j = 0;
        while (bytes_restantes > 0) {
            int bloque = bloques[i][j];
            fseek(stdin, (ini+1) + bloque * B, SEEK_SET); // Saltar al bloque correspondiente
            int leer = min(bytes_restantes, B);
            fread(&buffer[0], 1, leer, stdin);  // Leer el bloque
            fwrite(&buffer[0], 1, leer, stdout); // Imprimir contenido
            bytes_restantes -= leer;
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}