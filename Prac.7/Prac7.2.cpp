#include <iostream>
using namespace std;

struct Node {
  int patientID;
  Node *next;
};

Node *frontNode = NULL;
Node *rearNode = NULL;

void addPatient(int id) {
  Node *newNode = new Node;
  newNode->patientID = id;
  newNode->next = NULL;

  if (frontNode == NULL) {
    frontNode = newNode;
    rearNode = newNode;
  } else {
    rearNode->next = newNode;
    rearNode = newNode;
  }
}

int attendPatient() {
  Node *temp = frontNode;
  int id = temp->patientID;
  frontNode = frontNode->next;

  if (frontNode == NULL)
    rearNode = NULL;

  delete temp;
  return id;
}

void displayQueue() {
  cout << "Waiting patients: ";

  if (frontNode == NULL) {
    cout << "empty";
  } else {
    Node *temp = frontNode;
    while (temp != NULL) {
      cout << temp->patientID;

      if (temp->next != NULL)
        cout << " -> ";

      temp = temp->next;
    }
  }

  cout << "\n";
}

int main() {
  int operationCount;

  cout << "Enter number of operations: ";
  cin >> operationCount;

  cout << "Enter operations as J patientID (join) or S (attend).\n";

  for (int i = 0; i < operationCount; i++) {
    char operation;
    cout << "Operation " << i + 1 << ": ";
    cin >> operation;

    if (operation == 'J' || operation == 'j') {
      int id;
      cin >> id;
      addPatient(id);
    } else if (operation == 'S' || operation == 's') {
      if (frontNode == NULL) {
        cout << "Error: no patients are waiting.\n";
      } else {
        int id = attendPatient();
        cout << "Attended patient: " << id << "\n";
      }
    } else {
      cout << "Invalid operation. Use J or S.\n";
    }

    if (frontNode == NULL)
      cout << "Current front patient: none\n";
    else
      cout << "Current front patient: " << frontNode->patientID << "\n";

    displayQueue();
  }

  while (frontNode != NULL)
    attendPatient();

  return 0;
}
