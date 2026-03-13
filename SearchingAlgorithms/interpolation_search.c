#include <stdio.h>

int interpolation_search(int array[], int size, int target) {
  int low = 0;
  int high = size - 1;

  while (low <= high && target >= array[low] && target <= array[high]) {
    if (low == high) {
      return array[low] == target ? low : -1;
    }

    int pos = low + (int)(((double)(high - low) / (array[high] - array[low])) * (target - array[low]));

    if (array[pos] == target) {
      return pos;
    }
    if (array[pos] < target) {
      low = pos + 1;
    } else {
      high = pos - 1;
    }
  }

  return -1;
}

int main() {
  int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  int n = sizeof(data) / sizeof(data[0]);
  int target = 70;

  int index = interpolation_search(data, n, target);
  if (index == -1) {
    printf("Not found\n");
  } else {
    printf("Found %d at index %d\n", target, index);
  }

  return 0;
}
