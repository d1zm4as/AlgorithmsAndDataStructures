#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*

Uma fila (queue) é uma estrutura de dados linear que segue o padrão First-In-First-Out(FIFO) logo o primeiro elemento a ser adicionado na lista será o primeiro a ser removido,muito usada em papeis de manutenção de processos sequenciais.

Tem algumas operações básicas->

enqueue -> adiciona um elemento na fila

dequeue-> remove um elemento na frente da fila

peek-> retorna um elemento na frente sem remover

*/






#define N 5

int intArray[N];
int front = 0;
int rear = -1;
int itemCount = 0;


bool isEmpty() {
   if(itemCount==0){
        printf("vazio\n");
    }else{
        printf("Não tá vazio\n");

    }
    return 0;
}

bool isFull() {
    if(itemCount==N){
        printf("Cheio\n");
    }else{
        printf("Ainda tem espaço...\n");

    }
   
   return 0;
}
int peek() {
    if (itemCount==0) {
    printf("Tá vazio\n");
    }else{
   printf("%d\n",intArray[front]);}
   return 0;

}


int size() {
   printf("%d\n",itemCount);
   return 0;
}  

void enqueue() {
    int data;
   if(itemCount==N){
    printf("Tá cheio\n");
   } else{
    printf("Insira o valor a ser adicionado:" );
    scanf("%d",&data);
	
      if(rear == N-1) {
         rear = -1;            
      }       

      intArray[++rear] = data;
      itemCount++;
   printf("Adicionando %d\n",data);
   }

}

int dequeue() {
   if (itemCount==0) {
   printf("tá vazio \n");
   
   }else{
   int data = intArray[front++];
	
   if(front == N) {
      front = 0;
   }
	
   itemCount--;
   printf("tirando %d\n",data);
   }
   return 0;  
}
int main(){

int c;

    while(1){ 
    scanf("%d",&c);
        
        switch(c){
            case 0: exit(0);
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: isEmpty(); break;
            case 5: isFull(); break;
            default: printf("Please choose a correct option");       
      }  
   
}
    return 0;
}



