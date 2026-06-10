#include "arq_interface.h"
#include <time.h>

void imprimirLista(int *lista, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", lista[i]);
    }
}

int partition(int v[], int low, int high){
    int pivotIndex = low + rand() % (high - low + 1);
    int temp = v[low];
    v[low] = v[pivotIndex];
    v[pivotIndex] = temp;

    int pivo = v[low];
    int left = low + 1;
    int right = high;

    while(left <= right){
        while(left <= right && v[left] <= pivo){
            left++;
        }
        while(left <= right && v[right] >= pivo){
            right--;
        }
        
        if(left < right){
            temp = v[left];
            v[left] = v[right];
            v[right] = temp;
        }
    }
    temp = v[low];
    v[low] = v[right];
    v[right] = temp;

    return right;
}

void quicksort(int v[], int low, int high){
    if(low < high){
        int pivo = partition(v, low, high);
        quicksort(v, low, pivo - 1);
        quicksort(v, pivo + 1, high);
    }
}

int main(){
    int tam = 14;
    int lista[] = {225, 200, 100, 290, 250, 500, 900, 700, 300, 220, 215, 800, 600, 295};
    printf("\n");

    imprimirLista(lista, tam);
    printf("\n");
    quicksort(lista, 0, tam - 1);
    printf("\n");
    imprimirLista(lista, tam);
    printf("\n");

    return 0;
}