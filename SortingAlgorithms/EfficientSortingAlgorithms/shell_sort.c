#include <stdio.h>

/*
Shell sort using gap sequence n/2, n/4, ... , 1.
*/

void shellSort(int array[], int size) {
  for (int gap = size / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < size; i++) {
      int temp = array[i];
      int j = i;
      while (j >= gap && array[j - gap] > temp) {
        array[j] = array[j - gap];
        j -= gap;
      }
      array[j] = temp;
    }
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[] = {12, 34, 54, 2, 3};
  int n = sizeof(data) / sizeof(data[0]);

  printf("Unsorted Array\n");
  printArray(data, n);

  shellSort(data, n);

  printf("Sorted Array\n");
  printArray(data, n);

  return 0;
}
