#include <iostream>

using namespace std;


struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node *head) {
    if (head == nullptr) return;
    cout << head->data << " | " << head->next << " |" << endl;
    for (Node *p = head->next; p != head; p = p->next) {
        cout << p->data << " | " << p->next << " |" << endl;
    }
}

Node *insertAtBegin(Node *head, int data) {
    Node *temp = new Node(data);
    if (head == nullptr) {
        temp->next = temp;
        return temp;
    }
    Node *cur = head;
    while (cur->next != head) {
        cur = cur->next;
    }
    cur->next = temp;
    temp->next = head;
    return temp;
}

Node *insertAtEnd(Node *head, int data) {
    Node *temp = new Node(data);
    if (head == nullptr) {
        temp->next = temp;
        return temp;
    }
    Node *curr = head;
    while (curr->next != head) {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = head;
    return head;
}

Node *deleteHead(Node *head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == head) {
        delete head;
        return nullptr;
    }
    Node *curr = head;
    while (curr->next != head) {
        curr = curr->next;
    }
    curr->next = head->next;
    delete head;
    return curr->next;
}

int main() {

//    Node *head = new Node(10);
//    Node *temp1 = new Node(5);
//    Node *temp2 = new Node(20);
//    Node *temp3 = new Node(15);
//
//    head->next = temp1;
//    temp1->next = temp2;
//    temp2->next = temp3;
//    temp3->next = head;

    Node *head = nullptr;
    head = insertAtBegin(head, 10);
    head = insertAtBegin(head, 20);
    head = insertAtBegin(head, 30);
    head = insertAtEnd(head, 300);
    head = insertAtEnd(head, 340);
    head = insertAtEnd(head, 304);
    head = deleteHead(head);

    printList(head);


    return 0;
}
