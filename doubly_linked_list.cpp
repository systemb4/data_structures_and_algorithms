#include <iostream>

class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        // default constructor
        Node() {
            data = 0;
            next = NULL;
            prev = NULL;
        }

        // paramtized constructor
        Node(int n_data) {
            this->data = n_data;
            this->next = NULL;
            this->prev = NULL;
        }
};

class DoublyLinkedList {
    Node *head;
    public:
        // default constructor
        DoublyLinkedList() {
            head = NULL;
        }

        // class functions
        void addNodeEnd(int);
        void printList();
        void testPrint();
};

void DoublyLinkedList::printList() {
    Node *tmp = head;

    // check if anything in list
    if(head == NULL) {
        return;
    }

    // go through each element and print it
    while(tmp != NULL) {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

void DoublyLinkedList::testPrint() {
    Node *tmp = head;

    if(head == NULL) {
        return;
    }

    std::cout << tmp->data << std::endl;
    tmp = tmp->next;
    std::cout << tmp->data << std::endl;
    tmp = tmp->prev;
    std::cout << tmp->data << std::endl;
}

void DoublyLinkedList::addNodeEnd(int input_data) {
    Node *newNode = new Node(input_data);
    Node *headNode = head;

    if(head == NULL) {
        head = newNode;
        return;
    }

    while(headNode->next != NULL) {
        headNode = headNode->next;
    }

    headNode->next = newNode;
    newNode->prev = headNode;
}

int main() {
    DoublyLinkedList list1;

    list1.addNodeEnd(1);
    list1.addNodeEnd(2);
    list1.addNodeEnd(3);
    list1.addNodeEnd(4);

    list1.printList();
    std::cout << std::endl;
    list1.testPrint();

    return 0;
}
