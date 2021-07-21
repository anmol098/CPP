#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

void printList(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        //cout << " Date = " << curr->data << " Next = " << curr->next << " pRev = " << curr->prev << endl;
        cout << "| " << curr->prev << " | " << curr->data << " | " << curr->next << " |"<<endl;
        curr = curr->next;
    }
}

Node *insertBegin(Node *head, int data) {
    Node *temp = new Node(data);
    if (head == NULL) {
        return temp;
    }
    head->prev = temp;
    temp->next = head;

    return temp;
}

Node *insertEnd(Node *head, int data) {
    Node *temp = new Node(data);
    Node *curr = head;

    if (head == nullptr) {
        return temp;
    }

    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = temp;
    temp->prev = curr;
    return head;

}

Node *reverseDoubleLinkedList(Node *head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL) {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;

    }
    return prev->prev;
}

Node *deleteHead(Node *head) {
    if (head == nullptr)return nullptr;
    if (head->next == nullptr && head->prev == nullptr) {
        delete head;
        return nullptr;
    };

    Node *temp = head->next;
    temp->prev = nullptr;
    delete head;
    return temp;

}

Node *deleteEnd(Node *head) {
    if (head == nullptr)return nullptr;
    if (head->next == nullptr && head->prev == nullptr) {
        delete head;
        return nullptr;
    };
    Node *curr = head;
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
    return head;

}

Node *insertPos(Node *head, int pos, int data) {
    Node *curr = head;
    Node *temp = new Node(data);
    if (pos == 1) {
        temp->next = head;
        head->prev = temp;
        return temp;
    }

    for (int i = 0; i < pos - 2 && curr != nullptr; i++) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        return head;
    }

    temp->prev = curr;
    temp->next = curr->next;
    curr->next = temp;
    temp->next->prev = temp;

    return head;

}

int main() {

//    Node *head = new Node(10);
//    Node *temp1 = new Node(20);
//    Node *temp2 = new Node(30);
//
//    head->next = temp1;
//    temp1->prev = head;
//    temp1->next = temp2;
//    temp2->prev = temp1;

    Node *head = NULL;

    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
    head = insertEnd(head, 5);
    head = insertEnd(head, 0);

    //head = reverseDoubleLinkedList(head);
    //printList(head);
    cout << endl;
    head = insertPos(head, 5, 100);


    printList(head);
    return 0;
}
