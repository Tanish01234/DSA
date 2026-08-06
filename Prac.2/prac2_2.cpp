#include <iostream>
using namespace std;

int main() {

  int arr[] = {101, 102, 103, 104, 105, 106};
  int target = 102;
  int n = 6;
  int low = 0, high = n - 1;
  int mid;

  while (low <= high) {
    mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      break;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << arr[mid] << endl;
  cout << "Fount at index: " << mid;

  return 0;
}