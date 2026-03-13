#include <stdio.h>
#include <stdlib.h>

/*
Bucket sort for numbers in range [0, 1).
*/

typedef struct Node {
  float value;
  struct Node *next;
} Node;

Node *insert_sorted(Node *head, float value) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;

  if (head == NULL || head->value >= value) {
    node->next = head;
    return node;
  }

  Node *current = head;
  while (current->next != NULL && current->next->value < value) {
    current = current->next;
  }
  node->next = current->next;
  current->next = node;
  return head;
}

void bucketSort(float array[], int size) {
  Node **buckets = (Node **)calloc(size, sizeof(Node *));

  for (int i = 0; i < size; i++) {
    int index = (int)(array[i] * size);
    if (index < 0) index = 0;
    if (index >= size) index = size - 1;
    buckets[index] = insert_sorted(buckets[index], array[i]);
  }

  int idx = 0;
  for (int i = 0; i < size; i++) {
    Node *current = buckets[i];
    while (current != NULL) {
      array[idx++] = current->value;
      Node *temp = current;
      current = current->next;
      free(temp);
    }
  }

  free(buckets);
}

void printArray(float array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%.2f ", array[i]);
  }
  printf("\n");
}

int main() {
  float data[] = {0.42f, 0.32f, 0.33f, 0.52f, 0.37f, 0.47f, 0.51f};
  int n = sizeof(data) / sizeof(data[0]);

  printf("Unsorted Array\n");
  printArray(data, n);

  bucketSort(data, n);

  printf("Sorted Array\n");
  printArray(data, n);

  return 0;
}
