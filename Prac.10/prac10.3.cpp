#include <iostream>
using namespace std;

int main() {
  int n, m;
  cout << "enter size of hash table:";
  cin >> n;
  cout << "enter number of ids:";
  cin >> m;

  int table[50];

  for (int i = 0; i < n; i++) {
    table[i] = -1;
  }

  for (int i = 0; i < m; i++) {
    int id;
    cin >> id;
    int h1 = id % n;

    int h2 = 7 - (id % 7);

    int j = 0;
    int final_ind;

    while (j < n) {
      final_ind = (h1 + j * h2) % n;

      if (table[final_ind] == -1) {
        table[final_ind] = id;
        break;
      }
      j++;
    }
  }

  cout << "displaying ids of students:\n";

  for (int i = 0; i < n; i++) {
    cout << i << " : " << table[i] << endl;
  }

  return 0;
}