#include <stdio.h>
#include <stdlib.h>


/*
int a[] = {8,0,5,2,3,10,1};

O algoritmo consiste em dividir recursivamente um array em duas partes até que todas a partes tenham apenas 1 elemento, então o array é reconstruído ordenando o array de forma crescente.

1 -> O array é dividido em duas partes, todos os elementos com o index <= a mid(é a media aritmetica do primeiro e ultimo indice, no caso((6+0)/2 = 3) ficaram no subarray da esquerda e o resto na direita

int a[] = {8,0,5,2,3,10,1}; ->   {8,0,5,2}, {3,10,1}

2-> a divisão ocorre novamente-> {8,0} ,{5,2} , {3,10},{1}

3-> a divisão ocorre novamente-> {8},{0} ,{5},{2} , {3},{10},{1}

4-> a divisão ocorre novamente-> {8},{0} ,{5},{2} , {3},{10},{1}, os elementos foram divididos em sub-arrays, e agora serão ordenados

5-> Juntando os elementos de forma ordenada-> {0,8} ,{2,5} , {3,10},{1}

6-> Juntando os elementos de forma ordenada-> {0,2,5,8} , {1,3,10}

7 -> o array ordenado -> {0,1,2,3,5,8,10}


*/

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    //criando arrays temporários
    int L[n1], R[n2];
 
    //copiando elementos para os arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    //juntando
    i = 0; // Indexos do primeiro
    j = 0; // Indexos do segundo
    k = l; // Indexos do merge
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
   //copiado até o ultimo elemento de L
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    //copiando até o ultimo elemento de R
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
 

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
/* Driver code */
int main()
{
    int arr[] = {8,0,5,2,3,10,1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}