#include <stdio.h>
#include <stdlib.h>

/*
int a = {9,8,2,6,0};7

A ordenação começa com os dois primeiros termos do array(a[0] e a[1]), no caso {9,8}

int a = {9,8,2,6,0};

1º - É comparado a[0] com a[1], que resulta em, a[0] > a[1], então os valores das posições serão trocadas.

int a = {8,9,2,6,0};


2º - É comparado a[1] com a[2], que resulta em, a[1] > a[2], então os valores das posições serão trocadas, entretando o valor da posição a[2], ainda é menor doque a posição a[0], então haverá as seguintes trocas. 

int a = {8,2,9,6,0}; -> a[2] = 9 , a[1]=2 

int a = {2,8,9,6,0}; -> a[1] = 8 , a[1]=0


3º - É comparado a[2] com a[3], que resulta em, a[2] > a[3], então os valores das posições serão trocadas, entretando o valor da posição a[2], ainda é menor doque a posição a[1] e maior doq a posição a[0], então haverá as seguintes trocas. 

int a = {2,8,9,6,0}; -> a[3] = 9 , a[2]=6 

int a = {2,6,8,9,0}; -> a[2] = 8 , a[1]=6

4º - É comparado a[3] com a[4], que resulta em, a[3] > a[4], então os valores das posições serão trocadas, entretando o valor da posição a[2], ainda é menor doque a posição a[1] e  menor doq a posição a[0], então haverá as seguintes trocas. 

int a = {2,6,8,0,9}; -> a[4] = 9 , a[3]=0 

int a = {2,6,0,8,9}; -> a[3] = 8 , a[2]=0

int a = {2,0,6,8,9}; -> a[2] = 6 , a[1]=0

int a = {0,2,6,8,9}; -> a[1] = 2 , a[0]=0

O limite chega no int tam(tam sendo o tamanho do array) - int a = {0,2,6,8,9}; array ordenado final






*/


void InsertionSort(int array[], int tam){
    
    for(int i = 1;i<tam;i++){
    int j = i;
    int temp = array[i];
    while(j>0&&array[j-1]>temp){
        array[j]=array[j-1];
    j--;
    }
    array[j] = temp;
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
    int array[] = {9,8,2,6,0};
    int tam= sizeof(array)/sizeof(array[0]);
    InsertionSort(array,tam);
    printf("Ordenando....\n");
    printArray(array,tam);

    return 0 ;
}
