#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
Uma pilha(stack) é uma coleção de elementos que são inseridos e removidos de acordo com o Last-in-first-out(lifo), similar com uma pilha de livros.

A pilha é uma tipo abstrato de dados, focando mais no comportamento doq na implementação em sí

bastente usando para avaliar expressões, e guardar dados em cache etc

As operações básicas são:

push -> adiciona um elemento no topo da pilha

pop -> exclui o elemento do topo da pilha

peek-> deixa que o usuário veja oq tem no topo da pilha sem modifica-la

Todas operações acima são O(1),extremamente rápidas


*/



// tamanho da stack
#define N 5

//
int top = -1;

// usando array
int stack[N];

// Funções
void push();       
int pop();       
int peek();        
bool isEmpty();    
bool isFull();   

int main(){
    int c;

    while(1){ 
    scanf("%d",&c);
        
        switch(c){
            case 0: exit(0);
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: isEmpty(); break;
            case 5: isFull(); break;
            default: printf("Please choose a correct option");       
      }  
   
}
    return 0;
}
void push(){
    // Checking overflow state
    if(top == N-1)
        printf("Cheio");
    else{
        int x;
        printf("Qual elemento vai ser add? ");
        scanf("%d", &x);
        top+=1;
        stack[top] = x;
    }
}

int pop(){
    // Checking underflow state
    if(top == -1)
        printf("Tá vazio!\n");
    else{
        int x = stack[top];
        printf("Tirando %d\n", x);
        top-=1;
        return x;
    }
    return -1;
}

int peek(){
    int x = stack[top];
    printf("%d ta no topo\n", x);
    return x;
}

bool isEmpty(){
    if(top == -1){
        printf("Vázio\n");
        return true;
    }
    printf("Nãao ta vazio\n");
    return false;
}

bool isFull(){
    if(top == N-1){
        printf("Tá cheio\n");
        return true;
    }
    printf("Nâo ta cheio\n");
    return false;
}




