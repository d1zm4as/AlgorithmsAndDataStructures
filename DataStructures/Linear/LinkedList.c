#include <stdio.h>
#include <stdlib.h>



/*

Linked List é um coleção ordenada de elementos, esses elementos são chamados de nodes, muito util quando elementos precisam ser adicionados ou deletados no começo da lista

Cada nó contem dois campos:

ex:

Node{
    data: informação -> contem a informação do node
    next:Node -> aponta para o proximo nó

}
ex:

LinkedList{
        head:NodeA -> o campo head referencia o primeiro nó, se estiver nulo é porque a lista está vazia

        NodeA{                  
            data:pão
            next:NodeB
        }

        NodeB{
            data:9
            next:NodeC
        }

        NodeC{
            data:f20fj48f42442
            next:null-> represneta o fim da lista
        }

}
obs:podemos perceber que toda a lista pode ser percorrida por causa das referências(next), caso o NodeB não tenha a referêncai o NodeC não poderá ser acessado.
obs: vale lembrar que diferente do array(onde é possível acessar QUALQUER valor de forma arbitrária), aqui os valores so poderão ser acessados na sequência, o que deixa a operação de acesso O(n) no pior caso(quando o valor a ser acessado não for o primeiro) e O(1) quando o valor acessado for o primeiro 


obs: a lista acima é conhecida como singly-linked list


As desvantagens da Linked List é justamente o seu acesso(coisa que o array faz mt bem)

Vantagens:


Inserção no começo, ele bem simples->

queremos inserir o NodeD, no começo

basta criar um novo Nó D

NodeD{
    data:efafoefoaef
    next:NodeA -> e apontar para o antigo nó inicial
    
}

LinkedList{
        head:NodeD -> Mudamos a referência do head 
        NodeD{
            data:efafoefoaef
            next:NodeA -> e apontar para o antigo nó inicial
            }
        NodeA{                  
            data:pão
            next:NodeB
        }

        NodeB{
            data:9
            next:NodeC
        }

        NodeC{
            data:f20fj48f42442
            next:null-> represneta o fim da lista
        }

}


Inserção no meio e no fim->

queremos inserir o NodeE e o NodeF no final, no meio(meio sendo entre o nó inicial e final), basta procurar por um nó com a variável pred indentificada.

basta criar um novo Nó E

NodeE{
    data:efafoefoaef
    next:NodeA -> e apontar para o antigo nó inicial
    pred:NodeB
}
NodeF{
    data:eeeeee
    next:null:
    pred:NodeC
}

LinkedList{
        head:NodeD -> Mudamos a referência do head 
        NodeD{
            data:efafoefoaef
            next:NodeA -> e apontar para o antigo nó inicial
            }
        NodeA{                  
            data:pão
            next:NodeB
        }

        NodeB{
            data:9
            next:NodeE apontar para o proximo nó
        }
        NodeE{
        data:efafoefoaef
        next:NodeA -> e apontar para o proximo nó
        pred:NodeB
        }
        NodeC{
            data:f20fj48f42442
            next:NodeF
        }
        NodeF{
            data:eeeeee
            next:null-> represneta o fim da lista
            pred:Null
        }

}

Double Linked List-> É uma variação da linked list, possui uma referência Tail no fim(assim como head no começo), facilitando a inserção no final


*/
// Linked list no C


// Criando o Nó
// Linked list operations in C

#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node {
  int data;
  struct Node* next;
};

// Insert at the beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
  // Allocate memory to a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // insert the data
  new_node->data = new_data;

  new_node->next = (*head_ref);

  // Move head to new node
  (*head_ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node* prev_node, int new_data) {
  if (prev_node == NULL) {
  printf("the given previous node cannot be NULL");
  return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Insert the the end
void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref; /* used in step 5*/

  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
  *head_ref = new_node;
  return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}

// Delete a node
void deleteNode(struct Node** head_ref, int key) {
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key) {
  *head_ref = temp->next;
  free(temp);
  return;
  }
  // Find the key to be deleted
  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;

  free(temp);
}

// Search a node
int searchNode(struct Node** head_ref, int key) {
  struct Node* current = *head_ref;

  while (current != NULL) {
  if (current->data == key) return 1;
  current = current->next;
  }
  return 0;
}

// Sort the linked list
void sortLinkedList(struct Node** head_ref) {
  struct Node *current = *head_ref, *index = NULL;
  int temp;

  if (head_ref == NULL) {
  return;
  } else {
  while (current != NULL) {
    // index points to the node next to current
    index = current->next;

    while (index != NULL) {
    if (current->data > index->data) {
      temp = current->data;
      current->data = index->data;
      index->data = temp;
    }
    index = index->next;
    }
    current = current->next;
  }
  }
}

// Print the linked list
void printList(struct Node* node) {
  while (node != NULL) {
  printf(" %d ", node->data);
  node = node->next;
  }
}

// Driver program
int main() {
  struct Node* head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);

  printf("Linked list: ");
  printList(head);

  printf("\nAfter deleting an element: ");
  deleteNode(&head, 3);
  printList(head);

  int item_to_find = 3;
  if (searchNode(&head, item_to_find)) {
  printf("\n%d is found", item_to_find);
  } else {
  printf("\n%d is not found", item_to_find);
  }

  sortLinkedList(&head);
  printf("\nSorted List: ");
  printList(head);
}