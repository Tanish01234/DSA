#include <iostream>
using namespace std;

int recursiveSearch(int arr[], int target, int n) {
  if (n < 0) {
    return -1;
  }
  if (arr[n] == target) {
    return n;
  }
  return recursiveSearch(arr, target, n - 1);
}
int main() {
  int numPlate[11] = {1267, 2452, 1256, 6642, 6779, 9022,
                      7210, 2245, 6146, 1245, 2541};
  int target = 1267;
  int n = 10;

  for (int i = 0; i <= 10; i++) {
    if (numPlate[i] == target) {

      cout << "Number Plate " << numPlate[i] << " is Found at Index " << i
           << " : ";

      break;
    }else{
        cout << "Not Found" << endl;
        break;
    }
  }

  return 0;
}


// Recursive Method.