#include <stdio.h>
#include "functionsLib.h"

void printArray(int array[]){
    for(int i = 0; i < TAM; i++){
        printf("V[%d] = %d\n", i, array[i]);
    }
}

void printAuxArray(struct auxArray auxData[]){
    printf("\n");
    for(int i = 0; i < TAM; i++){
        printf("\n%d - Chave[%d] Posicao[%d]", i, auxData[i].key, auxData[i].position);
    }
}

void generateRandomArray(int array[]){
    srand((unsigned) time(NULL));

    for(int i = 0; i < TAM; i++){
        array[i] = rand() % 999;
    }
}

void keySearch1(struct auxArray auxData[], int key, int startEnd[]){
	int found = FALSE;
	for(int i = 0; i < TAM && found == FALSE; i++){
 		if(auxData[i].key > key){
       	    startEnd[0] = i-1;
            startEnd[1] = i;
			found = TRUE;
       }
    }
}

void keySearch2(int array[], int startEnd[], int key, struct auxArray auxData[]){
	int found = FALSE;
	for(int i = startEnd[0]; i <= startEnd[1] && found == FALSE; i++){
		if(array[i] == key){
			printf("\nChave encontrada na posicao %d no array.\n\n", i);
			found = TRUE;
		}
	}
	if(!found){
	    printf("\nChave nao encontrada.\n");
	}
}

void generateAuxArray(struct auxArray auxData[]){
    srand((unsigned) time(NULL));
    int index = 0;
    for(int i = 0; i < TAM; i++){
        auxData[i].key = rand() % 1000;
        auxData[i].position = index;
        index += 100; 
    }
}

void quicksort(int x[], int lb, int ub){

    int j = -1;

    if(lb >= ub)
        return;                     

    partition(x, lb, ub, &j);       

    quicksort(x, lb, j-1);

    quicksort(x, j+1, ub);          
}

void partition(int x[], int lb, int ub, int *j){

    int a, down, up, temp;
    
    a = x[lb];
    up = ub;
    down = lb;

    while(down < up){
        while(x[down] <= a && down < ub){
            down++;
        }
        while(x[up] > a){
            up--;
        }
        if(down < up){
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
        }
    }
    x[lb] = x[up];
    x[up] = a;
    *j = up;
}
