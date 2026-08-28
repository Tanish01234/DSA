#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void reverselist(node *head)
{
    if (head == NULL)
    {
        return;
    }
    reverselist(head->next);
    cout << head->data << " ->> ";
}

int main()
{
    node *head = NULL;
    int choice;

    int n;
    cout << "enter your number of operations : " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cout << "1 : insert at frount" << endl;
        cout << "2 : insert at end " << endl;
        cout << "3 : insert at any position" << endl;
        cout << "4 : delete at any position by value : " << endl;
        cout << "5 : Print reverse : " << endl;
        cout << "6 : display final list : " << endl
             << endl;
        cin >> choice;
        node *newnode = new node();
        if (choice == 1)
        {
            cout << "enter your data : " << endl;
            cin >> newnode->data;
            newnode->next = NULL;
            // if(head==NULL){
            //     head=newnode;
            //     tail=newnode;
            // }
            // else{
            // newnode->next=head;
            // head=newnode;
            // }
            if (head == NULL)
            {
                head = newnode;
            }
            else
            {
                newnode->next = head;
                head = newnode;
            }
            node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ->> ";

                temp = temp->next;
            }
            cout << "NULL";
            cout << endl<<endl;
        }
        else if (choice == 2)
        {
            cout << "enter your data : " << endl;
            cin >> newnode->data;
            newnode->next = NULL;
            
            if (head == NULL)
            {
                head = newnode;
            }
            else
            {
                node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
            node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ->> ";

                temp = temp->next;
            }
            cout << "NULL";
            cout << endl<<endl;
        }
        else if (choice == 3)
        {
            cout << "enter your data : " << endl;
            cin >> newnode->data;
            newnode->next = NULL;
            int position;
            cout << "enter your position : " << endl;
            cin >> position;
            if (position == 1)
            {
                newnode->next = head;
                head = newnode;
            }
            else
            {
                node *temp = head;
                for (int i = 1; i < position - 1; i++)
                {
                    if (temp == NULL)
                    {
                        cout << "Invalid position ! " << endl;
                        return 0;
                    }
                    temp = temp->next;
                }
                if (temp == NULL)
                {
                    cout << "Invalid position ! " << endl;
                }
                newnode->next = temp->next;
                temp->next = newnode;
            }
            node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ->> ";

                temp = temp->next;
            }
            cout << "NULL";
            cout << endl<<endl;
        }
        else if (choice == 4)
        {
            if (head == NULL)
            {
                cout << "SLL is empty ! " << endl;
            }
            else
            {
                int d;
                cout << "enter your value which you want to delete : " << endl;
                cin >> d;

                node *temp = head;
                while (temp->next != NULL)
                {

                    if (temp->next->data == d)
                    {
                        temp->next = temp->next->next;
                        break;
                    }
                    temp = temp->next;
                }

                while (temp != NULL)
                {
                    cout << temp->data << " ->> ";

                    temp = temp->next;
                }
                cout << "NULL";
                cout << endl<<endl;
            }
        }
        else if (choice == 5)
        {

            reverselist(head);
            cout << "NULL";
            cout << endl<<endl;
        }
        else if (choice == 6)
        {
            cout << "list : ";
            node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ->> ";

                temp = temp->next;
            }
            cout << "NULL";
            cout << endl;
        }
    }

    if (choice <= 0 && choice > 6)
    {
        cout << "invalid choice ";
    }
}
