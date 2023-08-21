#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define TAM 1000

struct auxArray{
    int key;
    int position;
};

void quicksort(int x[], int lb, int ub);
void partition(int x[], int lb, int ub, int *j);
void generateRandomArray(int array[]);
void generateAuxArray(struct auxArray auxData[]);
void keySearch1(struct auxArray auxData[], int key, int startEnd[]);
void keySearch2(int array[], int startEnd[], int key, struct auxArray auxData[]);
void printAuxArray(struct auxArray auxData[]);
