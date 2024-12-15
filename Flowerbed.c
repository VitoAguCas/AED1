#include <stdio.h>    
#include <stdbool.h>

bool CanPlaceFlowers(int* flowerbed, int flowerbedSize, int n);

int main(){

int flowerbed[]={ 0 };
int size = sizeof( flowerbed )/4;
int n = 1;
printf("%d",CanPlaceFlowers(flowerbed,size,n));
}

bool CanPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int canPlant = 0;
    int plantedLast = 0;
    if ( flowerbedSize == 1 ) {                                                                  //checa se o array tem tamanho 1
        if( flowerbed[0] == 0 )                                                                  
     canPlant++;
    }
    else for ( int i = 0 ; i < flowerbedSize ; i++ ) {                                           //se for maior que 1,passa por todo o array
        if ( plantedLast == 0 ) {
                if ( i == 0 ) {                                                                  //checa se é o primeiro termo
                    if ( flowerbed[i] == 0 && flowerbed[i+1] == 0 ) {                            //se o primeiro termo for vazio
                        canPlant++;                                      
                        plantedLast++;                                                              
                        }
                    }
                else if ( i == flowerbedSize - 1 ) {                                             //checa se é o ultimo
                    if ( flowerbed[i-1] == 0 && flowerbed[i] == 0 ) {       
                        canPlant++;                                      
                        plantedLast++;
                        }
                    }
                    else if ( flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0 ) {
                        canPlant++;                                                              //testa se o anterior, atual e proximo são
                        plantedLast++;                                                           //vazios, se sim, aumenta o contador e
                    }                                                                            //ativa a plantedLast
            }
            else
                plantedLast = 0;
    }
    if ( n <= canPlant )                                               
        return true;                                                   
    else
        return false;
}