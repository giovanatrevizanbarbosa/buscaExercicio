#include <stdio.h>
#include "functionsImpl.h"

int main(){
    int array[TAM];
    int keyArray[TAM];
    int startEnd[2] = {0};
    struct auxArray auxData[TAM];
    int key;

    generateRandomArray(array);
    generateAuxArray(auxData);

    for(int i = 0; i < TAM; i++){
        keyArray[i] = auxData[i].key;
    }

    quicksort(array, 0, TAM-1);
    quicksort(keyArray, 0, TAM-1);

    for(int i = 0; i < TAM; i++){
        auxData[i].key = keyArray[i];
    }

    printArray(array);
    printAuxArray(auxData);
    
    printf("\n\nDigite a chave a ser buscada: ");
    scanf("%d", &key);
    
    keySearch1(auxData, key, startEnd);
    printf("\nChave possivelmente entre [%d - %d]\n", startEnd[0], startEnd[1]);

	keySearch2(array, startEnd, key, auxData);

    return 0;
}