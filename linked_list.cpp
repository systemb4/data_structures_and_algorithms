#include <iostream>

class Node {
    public:
        int data;
        Node *next;

        // default constructor
        Node() {
            data = 0;
            next = NULL;
        }

        // paramtized constructor
        Node(int n_data) {
            this->data = n_data;
            this->next = NULL;
        }
};

class LinkedList {
    Node *head;
    public:
        // default constructor
        LinkedList() {
            head = NULL;
        }

        // class functions
        void addNode(int);
        void printList();
};

void LinkedList::printList() {
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

void LinkedList::addNode(int input_data) {
    Node *newNode = new Node(input_data);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node *tmp = head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

int main() {
    LinkedList list1;

    list1.addNode(1);
    list1.addNode(2);
    list1.addNode(3);
    list1.addNode(4);
    list1.addNode(5);

    list1.printList();

    return 0;
}
