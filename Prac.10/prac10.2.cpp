#include <iostream>
#include <vector>
using namespace std;

int main()

{
  int n;

  cout << "enter number of books : ";

  cin >> n;

  vector<vector<int>> stand(10);

  cout << "enter the book code :";

  for (int i = 0; i < n; i++) {
    int code;
    cin >> code;

    int ind = code % 10;

    stand[ind].push_back(code);
  }

  cout << "\nDISPLAYING THE BOOK STANDS\n";

  for (int i = 0; i < 10; i++) {
    cout << "Stand " << i << " : ";

    for (int j = 0; j < stand[i].size(); j++) {
      cout << stand[i][j] << " ";
    }

    cout << endl;
  }

  return 0;
}
