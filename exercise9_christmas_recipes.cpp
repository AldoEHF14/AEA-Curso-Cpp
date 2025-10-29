#include <stdio.h> 
 
int main() { 

    int max= 265000; 
    static char in [1024][16]; // arr de ingredientes 
    static char arrRec[265000][16]; // arr de recetas, a lo mucho solo puede guardar 250,000 palabras 
    int residuo=0 ; 
    int contador=0; 
    int regreso=0 ; 
    int marca= 0; // se utilizará para mover el arrRec cuando sea necesario debido a que hay mas de 250 palabras 
    int pr, pp, pi; // recetas , parejas , ingedientes

    scanf("%08d%08d%08d", &pr, &pp, &pi); 
    
    int rec = (pp - pr)/16; // num de recetas 
    int rela = pi - pp; // intervalo de las relaciones 

    if(rec > max){ 
        fread(&arrRec[0][0],16 ,max , stdin); /////// 
        //fwrite(&arrRec[0][0],16 ,2 , stdout); /////// 
        residuo = rec-max; 
    } 

    if(rec <=max){ 
        fread(&arrRec[0][0], 16 ,rec , stdin); 
    } 
 
    fseek(stdin, pi, SEEK_SET); 
    // leer ingredientes 
    fread(&in[0][0], 16, 1024, stdin ); 
 
    // Comienzo de impresion 
    fseek(stdin, pp, SEEK_SET); 
    int anterior = -1; 
    for (int i = 0; i < rela / 16; ++i) { 
        int receta; 
        int ingrediente; 
        scanf("%08d%08d", & receta, & ingrediente); 
        // printf("%d %d", receta, ingrediente); 
        if (receta < max && marca== 0) { //imprime receta si esta en arrRec 
            if (anterior != receta) { 
                fwrite(&arrRec[receta][0], 16, 1 , stdout); 
                contador++; 
                printf("\n"); 
            } 
        } if(receta >=max ) { // imprimimr receta si no esta en arrRec 
            // printf("entre receta >=4"); 
            if(marca== 0){ 
                fseek(stdin,pr+(contador*16), SEEK_SET); 
                fread(&arrRec[0][0], 16 ,residuo , stdin ); ///////// 
                marca = 1 ; 
                fseek(stdin, regreso+16 , SEEK_SET); // el regreso esta mal , tien algun offset 
                int prueba = ftell(stdin); 
                //printf("%d\n", prueba); 
                //fwrite(&arrRec[0][0], 16 ,residuo , stdout ); 
            } 
            if (anterior != receta) { 
                //printf("%d\n", receta); 
                fwrite(&arrRec[receta-contador][0], 16, 1 , stdout); 
                printf("\n"); 
            } 
        } 
        //imprimir ingre 
        printf("-"); 
        fwrite(&in[ingrediente][0], 16, 1 , stdout); 
        regreso= ftell(stdin); 
        //printf("%d", regreso); 
        printf("\n"); 
        anterior = receta; 
    }

    
    return 0;
}