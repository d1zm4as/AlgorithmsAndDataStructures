#include <stdio.h>



/*
int a[] = {2,9,4,8,7,1,5};
O selection sort essencialmente percorre todos os items do a[i] para achar o valor mínimo, após encontrar esse valor, ele será trocado
com o item mais a esquerda possível

ex:
int a[] = {2,9,4,8,7,1,5};

1º -> percorre o vetor até achar o valor mínimo, no caso o 1, coloca ele no canto mais a esquerda possível
int a[] = {1,9,4,8,7,2,5};-> o subvetor {1} já está ordenado,falta ordenar o subvetor {9,4,8,7,2,5}.

2º -> percorrer o vetor até achar o valor mínimo, no caso o 2, coloca ele no canto mais a esquerda possível
int a[] = {1,2,4,8,7,9,5};-> o subvetor {1,2} já está ordenado,falta ordenar o subvetor {4,8,7,9,5}.

3º -> percorrer o vetor até achar o valor mínimo, no caso o 4, coloca ele no canto mais a esquerda possível
int a[] = {1,2,4,8,7,9,5};-> o subvetor {1,2,4} já está ordenado,falta ordenar o subvetor {8,7,9,5}.

4º -> percorrer o vetor até achar o valor mínimo, no caso o 5, coloca ele no canto mais a esquerda possível
int a[] = {1,2,4,5,7,9,8};-> o subvetor {1,2,4,5} já está ordenado,falta ordenar o subvetor {7,9,8}.

5º -> percorrer o vetor até achar o valor mínimo, no caso o 7, coloca ele no canto mais a esquerda possível
int a[] = {1,2,4,5,7,9,8};-> o subvetor {1,2,4,5,7} já está ordenado,falta ordenar o subvetor {9,8}.


6º -> percorrer o vetor até achar o valor mínimo, no caso o 80, coloca ele no canto mais a esquerda possível
int a[] = {1,2,4,5,7,8,9};-> o subvetor {1,2,4,5,7,8,9} já está ordenado,falta ordenar o subvetor {}.



*/
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void selectionSort(int array[],int tam){
int i,j;
for(int i=0;i<tam-1;i++){
    int min=i;
    for(int j=i+1;j<tam-1;j++){ //{1,2,4,5,7,8,9};, tendo como referência, começo comparando o vetor[1] com o vetor[0]
        if(array[j]<array[min]){
            min = j;
        }
    }
    
    swap(&array[min], &array[i]);
    
}


}

void printArray(int array[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
        printf("%d ", array[i]);
    printf("\n");
}



int main(){
    int array[]={2,9,4,8,7,1,5};
    int tam = sizeof(array)/sizeof(array[0]);
    selectionSort(array,tam);
    printf("Ordenando......\n");
    printArray(array,tam);
    return 0;
}
