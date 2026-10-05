#include <iostream>
using namespace std;

class queue {
  int arr[100];
  int size;
  int front;
  int rear;

public:
  queue(int n) {
    size = n;
    front = -1;
    rear = -1;
  }

  void enqueue(int token) {
    if ((rear + 1) % size == front) {
      cout << "overflow queue" << endl;
      return;
    }

    if (front == -1) {
      front = 0;
    }

    else {
      rear = (rear + 1) % size;
    }

    arr[rear] = token;

    cout << "front:" << arr[front] << endl;
  }

  void dequeue() {
    if (front == -1) {
      cout << "underflow" << endl;
    }

    if (front == rear) {
      front = -1;
      rear = -1;
    }

    else {
      (front = front + 1) % size;
    }

    if (front != -1) {
      cout << "Front: " << arr[front] << endl;
    } else {
      cout << "Queue is empty" << endl;
    }
  }
};

int main() {
  int n;
  cin >> n;

  queue q(n);

  int z;
  cin >> z;

  for (int i = 0; i < z; i++) {
    string z;
    cin >> z;

    if (z == "enqueue") {
      int token;
      cin >> token;
      q.enqueue(token);
    }

    else if (z == "dequeue") {
      q.dequeue();
    }
  }
  return 0;
}