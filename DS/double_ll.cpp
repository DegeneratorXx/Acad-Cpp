#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    void push_front(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    void push_back(int data) {
        Node* newNode = new Node(data);
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        return;
    }
    void pop_front() {
        if (head == NULL) {
            return;
        }
        Node* toDelete = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete toDelete;
        return;
    }
    void pop_back() {
        if (tail == NULL) {
            return;
        }
        Node* toDelete = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
        delete toDelete;
        return;
    }
    void print() {
        Node* node = head;
        while (node != NULL) {
            std::cout << node->data << " ";
            node = node->next;
        }
        std::cout << std::endl;
        return;
    }
};

int main() {
    DoublyLinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    list.print(); // Output: 0 1 2
    list.pop_front();
    list.pop_back();
    list.print(); // Output: 1
    return 0;
}
