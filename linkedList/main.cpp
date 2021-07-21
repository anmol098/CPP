#include <iostream>

using namespace std;

//Single LL node
struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *insertAtBegin(Node *head, int x) {
    //create a temp node and point its next to the given head
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

Node *insertAtEnd(Node *head, int x) {
    //iterate the list last node poin to the new node
    Node *temp = new Node(x);
    if (head == NULL) {
        return temp;
    }
    Node *cur = head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = temp;
    return head;
}

Node *deleteAtBegin(Node *head) {
    //delete the begin store the next address in temp and delete the node and return the next node
    if (head == NULL) {
        return nullptr;
    } else {
        Node *temp = head->next;
        delete head;
        return temp;
    }
}

Node *deleteTail(Node *head) {
    // to delete teh tail stop at the second last node change the address to null and delte the enxt node
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        return nullptr;
    }
    Node *curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;

}

Node *insertPos(Node *head, int pos, int data) {
    //iterate to the pos-2 position then change the links
    Node *cur = head;
    Node *temp = new Node(data);
    if (pos == 1) {
        temp->next = head;
        return temp;
    }
    for (int i = 0; i < pos - 2 && cur != NULL; i++) {
        cur = cur->next;
    }
    if (cur == NULL)
        return head;
    temp->next = cur->next;
    cur->next = temp;
    return head;
}

bool searchInLinkedList(Node *head, int data) {
    Node *cur = head;
    int pos = 1;
    while (cur != NULL) {
        if (cur->data == data) {
            return true;
        }
        cur = cur->next;
        pos++;
    }
    return false;
}

int searchInLLRecursive(Node *head, int data) {
    if (head->next == NULL) {
        return -1;
    }
    if (head->data == data) {
        return 1;
    } else {
        int res = searchInLLRecursive(head->next, data);
        if (res == -1)
            return -1;
        else
            return (res + 1);
    }
}

Node *insertSorted(Node *head, int data) {
    //Insert the element in sorted LL keeping the LL sorted. Idea is simple travers the LL and check if the data of next node is grater then given node then insert and break
    Node *temp = new Node(data);
    if (head == nullptr) {
        return temp;
    }
    if (head->data > data) {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while (curr->next != nullptr) {
        if (curr->next->data > data) {
            // we have to insert
            temp->next = curr->next;
            curr->next = temp;
            break;
        }
        curr = curr->next;
    }
    if (curr->next == nullptr) {
        curr->next = temp;
    }
    return head;
}

Node *middleOfList(Node *head) {
    //idea is simple two pointer slow and fast slow will move one node and fast will move two node so when fast become null then slow will at middle
    if (head == nullptr)
        return head;
    if (head->next == nullptr) {
        cout << head->data;
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void printNfromEnd(Node *head, int n) {
    Node *second = head;
    Node *first = head;
    while (n - 1 > 0) {
        if (first == nullptr) {
            return;
        }
        first = first->next;
        n--;
    }
    while (first->next != nullptr) {
        second = second->next;
        first = first->next;
    }

    cout << second->data;
}

Node *reverseLL(Node *head) {
    // we will traverse the LL and keep reversing the link with two temproary node previous will store details of previous node and nex twill have next node info
    Node *curr = head;
    Node *prev = nullptr;
    while (curr != nullptr) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void removeDuplicate(Node *head) {
    Node *curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->data == curr->next->data) {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete (temp);
        } else {
            curr = curr->next;
        }
    }
}

bool isCycle(Node *head) {
    //floyed algo: if last node is pointing to some node in linked list.
    //slwo and fast pointer slow will move one node and fast ponter will move 2 node and some point they will meet if there is loop
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }

    }
    return false;
}

Node *detectAndRemoveLoop(Node *head) {
    //1. detect the meeting point of slow and fast pointer using floyd algo
    //2. then move slow pointer to starting of array
    //3. then move both pointer by 1 step now when they meet that will be the starting of loop
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (slow != fast) {
        return head;
    }

    slow = head;
    while (fast->next != slow->next) {
        slow = slow->next;
        fast = fast->next;
    }
    Node *curr = fast->next;
    fast->next = nullptr;
    return curr;
}

void deleteNode(Node *ptr) {
    //In this the pointer of any node till n-1 is given and you have to delete that node;
    //so the idea is we will copy the value from next to the given node and will delete the next node;
    Node *temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete (temp);
}

Node *segregate(Node *head) {
    //The question is in the linked list first print even elements then print odd elements;
    Node *es = nullptr;
    Node *ee = nullptr;
    Node *os = nullptr;
    Node *oe = nullptr;
    Node *cur = head;
    while (cur != nullptr) {
        if (cur->data % 2 == 0) {
            //it is even
            if (es == nullptr) {
                es = cur;
                ee = es;
            } else {
                ee->next = cur;
                ee = ee->next;
            }
        } else {
            // it is odd
            if (os == nullptr) {
                os = cur;
                oe = os;
            } else {
                oe->next = cur;
                oe = oe->next;
            }
        }
        cur = cur->next;
    }
    if (os == nullptr || es == nullptr) {
        return head;
    } else {
        ee->next = os;
        oe->next = nullptr;
        return es;
    }
}

int intersectionTwoLL(Node *head1, Node *head2) {
    // Traverse both Linked List ans count the number of nodes of both list
    // find the absolute diffrence of the both count
    // then ffrom the large LL skip the diffrence from the head then move the pointer on both list
    // the point at which the pointer meets that is the intersection point
    int c1 = 0;
    int c2 = 0;
    Node *curr = head1;
    Node *curr2 = head2;
    while (curr != nullptr) {
        c1++;
        curr = curr->next;
    }
    while (curr2 != nullptr) {
        c2++;
        curr2 = curr2->next;
    }
    int d = abs(c1 - c2);
    curr = head1;
    curr2 = head2;
    if (c1 > c2) {
        while (d > 0) {
            curr = curr->next;
            d--;
        }
    } else {
        while (d > 0) {
            curr2 = curr2->next;
            d--;
        }
    }
    while (curr != nullptr && curr2 != nullptr) {
        if (curr == curr2) {
            return curr2->data;
        }
        curr = curr->next;
        curr2 = curr2->next;
    }
    return -1;
}

Node *mergeSortLL(Node *head1, Node *head2) {
    // Idea is simple head and tail on node of LL which have the lowest data value then keep iterating the LL which has smaller value change tail to that node and move in that LL and at the end which ever is remaning merge it in tail and return the head
    Node *a = head1;
    Node *b = head2;
    Node *head = nullptr;
    Node *tail = nullptr;

    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }

    if (head1->data <= head2->data) {
        head = head1;
        tail = head1;
        a = a->next;
    } else {
        head = head2;
        tail = head2;
        b = b->next;
    }

    while (a != nullptr && b != nullptr) {
        if (b->data >= a->data) {
            tail->next = a;
            tail = a;
            a = a->next;

        } else {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    if (a != nullptr) {
        tail->next = a;
    } else {
        tail->next = b;
    }

    return head;
}

bool palindromeLL(Node *head) {
    //Idea is simple we have to find the middle of LL then after middle we have to reverse the second half of LL and start comparing each element from original and second half
    Node *curr = head;
    Node *middle = middleOfList(curr);
    Node *reverseAfterMiddle = reverseLL(middle);

    while (reverseAfterMiddle != nullptr) {
        if (curr->data != reverseAfterMiddle->data) {
            return false;
        }
        reverseAfterMiddle = reverseAfterMiddle->next;
        curr = curr->next;
    }

    return true;

}
int countPairs(struct Node* head1, struct Node* head2, int x) {
    // Code here
    Node *curr1 = head1;
    Node *curr2 = head2;
    int count = 0;

    while(curr1 != nullptr){
        int diff = x - curr1->data;
        if(searchInLinkedList(curr2, diff)){
            count++;
        }
        curr1 = curr1->next;
    }
    return count;

}

int main() {
    cout << "Hello, World!" << endl;
    Node *head = NULL;
    head = insertAtEnd(head, 7);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 3);

    Node *head1 = NULL;
    head1 = insertAtEnd(head1, 3);
    head1 = insertAtEnd(head1, 5);
    head1 = insertAtEnd(head1, 2);
    head1 = insertAtEnd(head1, 8);


//    head = segregate(head);
//    printList(head);
//    cout << endl;
//    printList(head1);
//    cout << endl;
    cout << countPairs(head, head1, 10);
//    head = mergeSortLL(head, head1);
//
//    cout << endl;
//    printList(head);


    //printList(head);


    return 0;
}
