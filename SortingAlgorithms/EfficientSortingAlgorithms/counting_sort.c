#include <stdio.h>
#include <stdlib.h>

/*
Counting sort for non-negative integers.
Time: O(n + k) where k is max value.
*/

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void countingSort(int array[], int size, int max_value) {
  int *count = (int *)calloc(max_value + 1, sizeof(int));
  int *output = (int *)malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  for (int i = 1; i <= max_value; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }

  free(count);
  free(output);
}

int main() {
  int data[] = {4, 2, 2, 8, 3, 3, 1};
  int n = sizeof(data) / sizeof(data[0]);
  int max_value = 8;

  printf("Unsorted Array\n");
  printArray(data, n);

  countingSort(data, n, max_value);

  printf("Sorted Array\n");
  printArray(data, n);

  return 0;
}
