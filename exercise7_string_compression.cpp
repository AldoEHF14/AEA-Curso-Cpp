#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

static char cadena[1000000+1]; // Hasta 1,000,000 de caracteres 


void comprimir(char *cadena) { 
    int len = strlen(cadena); 
    //printf("%d - ",len);
    int i=0;
    while (i < len) { 
        char actual = cadena[i]; 
        int n = 0; 
 
        while (i + n < len && cadena[i + n] == actual) { 
            n++; 
        } 
 
        if (n == 1) { 
            // Si la longitud es 1, imprimir el carácter directamente 
            printf("%c", actual); 
        } else { 
            // Si la longitud es mayor a 1 
            int M = n - 2; 
            //printf("\ncout:%d - M:%d - M:%b - binario: %b",n,M,M,actual);
            do { 
                int aux = M & 0b1111111; // Extraer los últimos 7 bits 
                //printf(" aux: %b- aux:%d\n",aux,aux);
                printf("%c", aux + 128);
                
                M >>= 7; // Desplazar M 7 bits a la derecha 
                //printf("\nM:%d - M:%b",M,M);
            } while (M != 0); 
            printf("%c", actual); 
        } 
 
        i += n; 
    } 
    //printf("\n"); 
}


void descomprimir(char *cadena) { 
    int len = strlen(cadena);
    int i = 0;
    int N=0;

    while (i < len) {
        char actual = cadena[i];
        //printf("%b ",actual);

        if (actual < 128 && actual>0) { 

            if (N == 0) {
                printf("%c", actual); 
            } else {
                // Si hay un valor acumulado en N, imprimir el carácter N veces
                for (int j = 0; j < N; j++) {
                    printf("%c", actual);
                }
                N = 0; // Resetear N después de usarlo
            }

        } else {
            
            int aux = actual & 0b01111111; // Extraer los últimos 7 bits
            int preludio2 = 0,preludio3 = 0;
            N = aux;

            int aux_b=0,aux_c=0;
            if (i + 1 < len && !((unsigned char)cadena[i+1] < 128)) {
                int aux_b = cadena[i+1] & 0b01111111; // Extraer los últimos 7 bits
                aux_b <<= 7; // Desplazar M 7 bits a la derecha 
                //printf("%b ", c); 
                preludio2 = aux + aux_b;
                //printf("%d ", aux_suma);
                N = preludio2; 
                if (i + 1 < len && !((unsigned char)cadena[i+2] < 128)){
                    aux_c = cadena[i+2] & 0b01111111; // Extraer los últimos 7 bits
                    aux_c <<= 14; // Desplazar M 7 bits a la derecha 
                    //printf("%b ", c); 
                    preludio3 = preludio2 + aux_c;
                    //printf("%d ", aux_suma);
                    N = preludio3; 
                    i++;
                }
                i++;
            }

            N +=2;
            //printf("%d",N);

        }
        i++;
    }

    //printf("\n"); 
}
 
int main() { 

    char P,cad;
    int cont=0;

    // Leer la entrada
    //scanf("%c ", &P);  // Leer el p ('C' o 'D')
    scanf("%c ", &P);
    //printf("%c",P);

    /*while (scanf("%c",&cad) == 1){
        //printf("%c\n",cad);
        cadena[cont] = cad;
        cont++;
    }*/
    scanf("%s ", cadena);

    
    if (P == 'C') {
        comprimir(cadena);
    } else if (P == 'D') {
        descomprimir(cadena);
    }
 
    return 0; 
}