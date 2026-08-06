#include <iostream>
using namespace std;

int recursiveBinarySearch(int arr[], int n, int target, int low, int high) {
  if (low > high) {
    return -1;
  }
  int mid = low + (high - low) / 2;
  if (arr[mid] == target) {
    return mid;
  } else if (arr[mid] < target) {
    return recursiveBinarySearch(arr, n, target, mid + 1, high);
  } else {
    return recursiveBinarySearch(arr, n, target, low, mid - 1);
  }
}

int main() {
  int arr[] = {101, 102, 103, 104, 105, 106};
  int n = 6;
  int target = 102;
  int low = 0, high = n - 1;

  recursiveBinarySearch(arr, n, target, low, high);
  return 0;
}
