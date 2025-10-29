#include <algorithm> 
#include <stdio.h> 
 
 void trie_recursivo(int pos_actual,char s[], int nivel ){ 
    int tam; 
    scanf("%02d", &tam); 
 
    char term; 
    scanf("%c", &term); 
 
    char letras[tam]; 
    for(int i = 0 ; i<tam ; ++i){ 
    scanf("%c", &letras[i]); 
    } 
 
    int pos[tam]; 
    for(int i = 0 ; i<tam ; ++i){ 
    scanf("%08d", &pos[i]); 
    } 
 
 
    if(term=='T' ){ 
    s[nivel] = '\0'; 
     printf("%s\n", s); 
 
    } 
      if(tam== 0){ 
     return; 
    } 
 
 
 
   for(int i= 0 ; i< tam; ++i){ 
        s[nivel]= letras[i]; 
        fseek(stdin, pos[i] , SEEK_SET); 
        int nuevo= ftell(stdin); 
        trie_recursivo(nuevo, s , nivel +1); 
   } 

 } 
 
int main(){ 
    int arr[220000]; 
    int tam; 
    char term; 
    int hijo; 
    int j= 0 ; 
    int raiz; 
    //fase 1 

    while(scanf("%02d", &tam) == 1){ 
    scanf("%c", &term); 
    
    for(int i = 0 ; i< tam ; ++i){ 
        scanf("%c", &term); 
    } 
    
    for(int i = 0 ; i< tam ; ++i){ 
        scanf("%08d", &hijo); 
        arr[j]= hijo; 
        ++j; 
    } 
    
    } 
    
    std::sort(&arr[0], &arr[j]); 
    //fase 2 
    rewind(stdin); 
    while(scanf("%02d", &tam) == 1){ 
        int actual; 
        actual= ftell(stdin)-2; 
        scanf("%c", &term); 
        
        for(int i = 0 ; i< tam ; ++i){ 
            scanf("%c", &term); 
        } 
        
        for(int i = 0; i < tam; ++i ){ 
            scanf("%08d", &hijo); 
            if(std::binary_search(&arr[0], &arr[j], actual)== true){ 
            }else{ 
            raiz = actual; 
            //printf("raiz: %d", raiz); 
            } 
        } 
    }
    
    fseek(stdin, raiz, SEEK_SET); 
    char s[4+1] = { }; 
    trie_recursivo(raiz, s, 0); 
    
}