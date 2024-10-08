#include <iostream>
// COMSC-210 | Lab 17 | Kylie Roxo
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);//function prototypes 
void addfront(Node *);
void deletenode(Node *);
void insertnode(Node *);
void deletelist(Node *);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { 
            head = newVal;
            addfront(newVal);//call function
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        deletenode(current);//call function
    }
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    insertnode(newnode);//call function
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    deletelist(head);//call function

    head = nullptr;
    output(head);

    return 0;
}

void addfront (Node * NV){//newValue to next to point to nullptr
    NV->next = nullptr;
}

void deletenode (Node * CU){//delete and then equal to nullptr
    delete CU;
    CU = nullptr;
}
void insertnode (Node * NM){//make newmode to value equal 10000
    NM->value = 10000;
    
}
void deletelist (Node * hd){//add in current to get the delete command and then delete the list 
    Node * current = hd;
    while (current) {
        hd = current->next;
        delete current;
        current = hd;
    }
}
void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}