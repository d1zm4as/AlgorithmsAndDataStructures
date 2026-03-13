#include <stdio.h>
#include <stdlib.h>

/*
Radix sort (LSD) for non-negative integers.
Uses counting sort per digit.
*/

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int getMax(int array[], int size) {
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

void countingSortByDigit(int array[], int size, int exp) {
  int output[size];
  int count[10] = {0};

  for (int i = 0; i < size; i++) {
    int digit = (array[i] / exp) % 10;
    count[digit]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    int digit = (array[i] / exp) % 10;
    output[count[digit] - 1] = array[i];
    count[digit]--;
  }

  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

void radixSort(int array[], int size) {
  int max = getMax(array, size);
  for (int exp = 1; max / exp > 0; exp *= 10) {
    countingSortByDigit(array, size, exp);
  }
}

int main() {
  int data[] = {170, 45, 75, 90, 802, 24, 2, 66};
  int n = sizeof(data) / sizeof(data[0]);

  printf("Unsorted Array\n");
  printArray(data, n);

  radixSort(data, n);

  printf("Sorted Array\n");
  printArray(data, n);

  return 0;
}
