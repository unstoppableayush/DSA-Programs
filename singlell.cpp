#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};

class SingleLinkedList {
private:
    Node *head;
public:
    SingleLinkedList() {
        head = nullptr;
    }

    void insert(int data) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    SingleLinkedList linkedList;
    linkedList.insert(1);
    linkedList.insert(2);
    linkedList.insert(3);
    linkedList.insert(4);

    cout << "The linked list is: ";
    linkedList.display();

    return 0;
}
