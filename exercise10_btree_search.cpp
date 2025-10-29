#include <stdio.h>
 
 
bool busca(int buscar , int ini, int pos_actual){ 
   
    if(pos_actual==-1){ 
    return false; 
   } 
 
   fseek(stdin, ini + pos_actual, SEEK_SET); 
   int tam; 
   int claves[340]; 
   int hijos[340+1]; 
 
    scanf("%04d", &tam); 
    //leer 340 claves fread 
    fread(&claves[0] ,4 ,340, stdin ); 
    //leer tam +1 hijos %08d 
    for(int i = 0 ; i < 340+1; ++i){ 
          scanf("%08d", &hijos[i] ); 
    } 

 
    for (int i = 0; i < tam; i++) { 
        if (claves[i] == buscar) { // si se encuentra en claves se acaba 
            return true; 
           } 
        if (buscar < claves[i] ) { // si es menor debe esatr en el hijo de la izquiera 
            return busca(buscar, ini, hijos[i]); 
        } 
        if (i+1 < tam ){ 
           if (buscar > claves[i] && buscar < claves[i+1]) { // si es mayor debe estar en el hijo de la derecha 
               return busca(buscar, ini, hijos[i+1]); 
           } 
        }if(i+1 >= tam){ 
          return busca(buscar, ini, hijos[i+1]); 
        } 
  } 
 
} 
 
int main(){ 
   int q; 
   int arr[100]; 
   scanf("%d ", &q); 
  //  getchar(); 
   fread(&arr[0], 4 , q , stdin); 
 
   getchar(); 
   int ini= ftell(stdin); 
 
 
   for(int i= 0 ; i<q ; ++i){ 
      printf("%d\n", busca(arr[i], ini, 0)); 
   } 
}