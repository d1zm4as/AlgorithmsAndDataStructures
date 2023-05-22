#include <stdio.h>
#include <stdlib.h>
/*
Um array é uma organização de elementos acessível por index
*/
int main(){
    int array []={8,5,0,1,4,9,3};
    // cada item nesse array é denominado elemento e cada elemento tem um inteiro index associado a ele
    int tam = sizeof(array)/sizeof(array[0]);
    // começando do 0 até o tamanho do array -1 
    // arrays podem conter, chars, floats e ints, algumas linguagens so permitem um tipo específico por array,outras aceitam vários tipos num array só

    // Os elementos do array podem ser acessados de forma arbitrária(não precisa seguir a ordem crescente do index)
    // A velocida da operação de acesso por index é extramente rápida O(1)
    //ex 
    printf("%d\n",array[0]);
    printf("%d\n",array[4]);
    printf("%d\n",array[1]);

    // a grande utilidade do array, é guardar grandes quantidades de elementos e facilitar o seu acesso.

    //Há dois tipos de arrays, estáticos e dinâmicos, há terminologia tem haver com o tamnho
    //ex:

    int lista[3];//-> esse array so poderar conter apenas 3 elementos
    int size = 3;
    int *din = (int*)malloc(size * sizeof(int)); 
    // o vetor din começa com apenas 3 elementos, mas poderá receber mais caso necessário.
    /*
    ex:

    int a [5]= {1,2,3,4,,}
    
    o array a tem tamanho 5, se quisermos inserir mais dois elementos(5,6)->
    
    int a [5]= {1,2,3,4,5} -> o espaço de memória do 5 já foi declarado mas o do 6 não.
    
    Quando isso acontece no array dinâmico um novo(copia) array é criado, com o dobro da capacidade do primeiro

    int a[10] = {1,2,3,4,5,6,,,,}, o 6 foi alocado(observe que 4 novos espaços de memória foram declarados junto )

    essa operação se repete toda vês que o espaço de  memória  declarado não for suficiente para o número de elementos.

    O tempo dessa operação toda é O(n),não tão rápido assim, é claro que a quantidade de vezes que essa operação ocorre importa.

    <quantidade de vezes == >otimização, como no nosso caso o tamanho dobra toda ves, seria mais ou menos um O(log n), mais rapido doq O(n)

    obs: n -> quantidade de operações


    






















    
    
    */
    /*
    recomendações de uso->

    Estático -> quando sabemos exatamente o quanto de elementos(subsequentemente de memória) sera necessário.

    Dinâmico -> quando não sabemos a quantidade de elementos (subsequentemente de memória) sera necessário.

    Obs: O uso indevido de ambos poderá causar excesso ou disperdício  de memória    
    
    */

    return 0;
}












