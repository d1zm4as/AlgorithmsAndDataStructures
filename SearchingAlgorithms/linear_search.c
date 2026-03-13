#include <stdio.h>

int linear_search(int array[], int size, int target) {
  for (int i = 0; i < size; i++) {
    if (array[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  int data[] = {5, 3, 8, 4, 2, 9};
  int n = sizeof(data) / sizeof(data[0]);
  int target = 4;

  int index = linear_search(data, n, target);
  if (index == -1) {
    printf("Not found\n");
  } else {
    printf("Found %d at index %d\n", target, index);
  }

  return 0;
}
