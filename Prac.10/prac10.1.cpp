#include <iostream>
using namespace std;

class vehical {
  int arr[10];

public:
  vehical() {
    for (int i = 0; i < 10; i++) {
      arr[i] = -1;
    }
  }
  void enter() {

    int n;
    cout << "enter number of vehicles:";
    cin >> n;

    cout << "enter registed no of vehicles:\n";

    for (int i = 0; i < n; i++) {
      int reg;
      cin >> reg;

      int index = reg % 10;

      while (arr[index] != -1) {
        index = (index + 1) % 10;
      }

      arr[index] = reg;
    }
  }

  void display() {
    for (int i = 0; i < 10; i++) {
      cout << "overall parking slots: " << arr[i] << endl;
    }
  }
};

int main() {
  vehical v;

  v.enter();
  v.display();
  return 0;
}