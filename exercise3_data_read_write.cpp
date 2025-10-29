#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

static int par[100000]={};
static int impar[100000]={};

using namespace std;

// Ordenamiento por selección para una fila

int main(){
    //FILE* arch = stdin;fopen("archivo.txt","r");

    /*if(arch == nullptr){
        printf("Error");
        return 0;
    }*/

    char E,S;
    int n,pars=0,impars=0;
    int ret = scanf(" %c %c\n", &E, &S);
    if (ret != 2) {
        // Manejar el error de lectura
        printf("Error leyendo E y S\n");
        return 1;
    }
    //printf("%c%c\n",E,S);


    if ( E == 'T'){
         while (scanf("%d",&n) == 1) {
            //printf("%d\n",n);
            if (n % 2 == 0) {
                par[pars] = n;  // Almacenar el número par en el arreglo par
                pars++;         // Incrementar el contador de pares
            } else {
                impar[impars] = n;  // Almacenar el número impar en el arreglo impar
                impars++;           // Incrementar el contador de impares
            }
        }
    }else{
        while(fread(&n,sizeof(int),1,stdin)==1){
            //printf("%d\n",n);
            if (n % 2 == 0) {
                par[pars] = n;  // Almacenar el número par en el arreglo par
                pars++;         // Incrementar el contador de pares
            } else {
                impar[impars] = n;  // Almacenar el número impar en el arreglo impar
                impars++;           // Incrementar el contador de impares
            }
        }
    }

    
    sort(par, par+ pars);
    sort(impar, impar+ impars);

    

    if ( S == 'B'){
        //printf("Imprimir pares = %d\n", pars);
        for (int i = 0; i < pars; i++) {
            fwrite(&par[i],sizeof(int),1,stdout);
        }
        // Imprimir los números impares
        //printf("Imprimir impares = %d\n", impars);
        for (int i = impars-1; i >= 0; i--) {
            fwrite(&impar[i],sizeof(int),1,stdout);
        }
    }else{
        //printf("Imprimir pares = %d\n", pars);
        for (int i = 0; i < pars; i++) {
            printf("%d\n", par[i]);
        }
        // Imprimir los números impares
        //printf("Imprimir impares = %d\n", impars);
        for (int i = impars-1; i >= 0; i--) {
            printf("%d\n", impar[i]);
        }

    }
    

    //fclose(arch);

    return 0;
}