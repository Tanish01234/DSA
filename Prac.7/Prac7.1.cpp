#include <iostream>
using namespace std;

const int MAX = 100;

int arr[MAX];
int front = -1;
int rear = -1;
int arrayCount = 0;
int capacity;

struct Node {
  int data;
  Node *next;
};

Node *frontNode = NULL;
Node *rearNode = NULL;
int linkedCount = 0;

void insertArray(int value) {
  if (front == -1)
    front = 0;

  rear = (rear + 1) % capacity;
  arr[rear] = value;
  arrayCount++;
}

int deleteArray() {
  int value = arr[front];
  arrayCount--;

  if (arrayCount == 0) {
    front = -1;
    rear = -1;
  } else {
    front = (front + 1) % capacity;
  }

  return value;
}

void displayArray() {
  cout << "Array: [ ";

  for (int i = 0; i < capacity; i++) {
    int found = 0;

    for (int j = 0; j < arrayCount; j++) {
      int position = (front + j) % capacity;
      if (position == i)
        found = 1;
    }

    if (found == 1)
      cout << arr[i] << " ";
    else
      cout << "_ ";
  }

  if (arrayCount == 0)
    cout << "]  front: none, rear: none\n";
  else
    cout << "]  front index: " << front << ", rear index: " << rear << "\n";
}

void insertLinked(int value) {
  Node *newNode = new Node;
  newNode->data = value;
  newNode->next = NULL;

  if (frontNode == NULL) {
    frontNode = newNode;
    rearNode = newNode;
  } else {
    rearNode->next = newNode;
    rearNode = newNode;
  }

  linkedCount++;
}

int deleteLinked() {
  Node *temp = frontNode;
  int value = temp->data;
  frontNode = frontNode->next;

  if (frontNode == NULL)
    rearNode = NULL;

  delete temp;
  linkedCount--;
  return value;
}

void displayLinked() {
  cout << "Linked list: ";

  if (frontNode == NULL) {
    cout << "empty";
  } else {
    Node *temp = frontNode;
    while (temp != NULL) {
      cout << temp->data;

      if (temp == frontNode)
        cout << " (front)";
      if (temp == rearNode)
        cout << " (rear)";

      if (temp->next != NULL)
        cout << " -> ";

      temp = temp->next;
    }
  }

  cout << "\n";
}

int main() {
  int operationCount;

  cout << "Enter maximum number of tokens (up to " << MAX << "): ";
  cin >> capacity;

  if (capacity <= 0 || capacity > MAX) {
    cout << "Invalid capacity.\n";
    return 0;
  }

  cout << "Enter number of operations: ";
  cin >> operationCount;

  cout << "Enter operations as J token (join) or S (serve).\n";

  for (int i = 0; i < operationCount; i++) {
    char operation;
    cout << "Operation " << i + 1 << ": ";
    cin >> operation;

    if (operation == 'J' || operation == 'j') {
      int value;
      cin >> value;

      if (arrayCount == capacity) {
        cout << "Error: queue is full.\n";
      } else {
        insertArray(value);
        insertLinked(value);
      }
    } else if (operation == 'S' || operation == 's') {
      if (arrayCount == 0) {
        cout << "Error: queue is empty.\n";
      } else {
        int servedToken = deleteArray();
        deleteLinked();
        cout << "Served token: " << servedToken << "\n";
      }
    } else {
      cout << "Invalid operation. Use J or S.\n";
    }

    if (arrayCount == 0)
      cout << "Current front token: none\n";
    else
      cout << "Current front token: " << arr[front] << "\n";

    displayArray();
    displayLinked();
  }

  while (frontNode != NULL)
    deleteLinked();

  return 0;
}
