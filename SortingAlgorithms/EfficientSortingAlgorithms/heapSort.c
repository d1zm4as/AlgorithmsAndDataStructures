#include <stdio.h>

/*

Dado o array,

int array[] = {2,0,9,8,1,5,4,3,15,7};

Esse array pode ser reprensentada como uma árovere binária


ex:                                            
                                (2)
                               /   \
                              /     \
                            (0)     (9)
                           /  \      /  \
                          /   (1)   (5)  (4)
                        (8)   / 
                        / \  (7)
                      /    \
                    (3)    (15)



A regra é seguinte o nó pai, vai ter um filho esquerda com o index(2i+1) e pra direita com (2i+2)

ex:

o nó pai (2) tem o index(0) ele vai ter um filho pra direita seguindo regra(2i+2, 2(0)+2 = array[2], 9)

o nó pai (2) tem o index(0) ele vai ter um filho pra esquerda seguindo regra(2i+1, 2(0)+1 = array[1], 0)

e a mesma lógica vai ser aplicada para o resto dos nós 


heap -> é uma árvore binária que obedece as seguintes condições ->

1 - Todos os níveis com execessão do ultimo estão cheios

2 - os valores dos nós pais não são menores que os valores do nós filhos




*/


void swap(int* a, int* b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int arr[], int N, int i)
{
    
    int largest = i;

    
    int left = 2 * i + 1;

    
    int right = 2 * i + 2;

    
    if (left < N && arr[left] > arr[largest])

        largest = left;

    
    if (right < N && arr[right] > arr[largest])

        largest = right;

    
    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{

    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    heapSort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);
}
