#include <iostream>
using namespace std;

class Queue {
  int arr[1000];
  int front;
  int rear;

public:
  Queue() {
    front = -1;
    rear = -1;
  }

  void arrive(int patient) {
    if (front == -1) {
      front = 0;
      rear = 0;
    } else {
      rear++;
    }

    arr[rear] = patient;

    cout << "Front: " << arr[front] << endl;
  }

  void attend() {
    if (front == -1) {
      cout << "Underflow" << endl;
      return;
    }

    cout << "Attended: " << arr[front] << endl;

    if (front == rear) {
      front = -1;
      rear = -1;
    } else {
      front++;
    }

    if (front != -1) {
      cout << "Front: " << arr[front] << endl;
    } else {
      cout << "Queue is empty" << endl;
    }
  }
};

int main() {
  Queue q;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string operation;
    cin >> operation;

    if (operation == "arrive") {
      int patient;
      cin >> patient;

      q.arrive(patient);
    } else if (operation == "attend") {
      q.attend();
    }
  }

  return 0;
}