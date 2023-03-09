#include <iostream>

#define HASHMAX 10

class Node {
    std::string name;
    public:
        Node *next;

        Node() {
            name = "Test";
            next = NULL;
        }

        Node(std::string n_name) {
            name = n_name;
            next = NULL;
        }

        std::string getName() {
            return name;
        }
};

class LinkedList {
    Node *head;
    public:
        LinkedList() {
            head = NULL;
        }

        void addToEnd(std::string);
        void printList();

        Node *getHead() {
            return head;
        }
};

LinkedList **hashArr;

void LinkedList::addToEnd(std::string n_name) {
    Node *newNode = new Node(n_name);

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

void LinkedList::printList() {
    Node *tmp = head;
    while(tmp->next != NULL) {
        std::cout << tmp->getName() << std::endl;
    }
}

int hashFunction(std::string name) {
    int sum = 0;

    for(int i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }

    return sum % HASHMAX;
}

void hashSort(int hashNum, std::string name) {
    hashArr[hashNum]->addToEnd(name);
}

int main() {
    hashArr = new LinkedList*[HASHMAX];
    for(int i = 0; i < HASHMAX; i++) {
        hashArr[i] = new LinkedList();
    }

    hashSort(hashFunction("Lukas"), "Lukas");
    LinkedList *head = hashArr[2];
    Node *headT = head->getHead();
    //headT = headT->next;
    std::cout << headT->getName() << std::endl;

    return 0;
}
