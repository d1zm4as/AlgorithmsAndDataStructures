#include <stdio.h>

int binary_search(int array[], int size, int target) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (array[mid] == target) {
      return mid;
    }
    if (array[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int main() {
  int data[] = {1, 3, 4, 6, 8, 10, 12};
  int n = sizeof(data) / sizeof(data[0]);
  int target = 8;

  int index = binary_search(data, n, target);
  if (index == -1) {
    printf("Not found\n");
  } else {
    printf("Found %d at index %d\n", target, index);
  }

  return 0;
}
