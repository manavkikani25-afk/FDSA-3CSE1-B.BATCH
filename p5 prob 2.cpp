#include <iostream>
using namespace std;

struct Node {
    string name;
    Node *next, *prev;
};

class Circular {
    Node* head = NULL;

public:
    void join(string s) {
        Node* n = new Node{s, NULL, NULL};

        if (!head) {
            head = n;
            n->next = n->prev = n;
        } else {
            Node* t = head->prev;
            n->next = head;
            n->prev = t;
            t->next = n;
            head->prev = n;
        }
    }

    void leave(string s) {
        if (!head) return;

        Node* t = head;
        do {
            if (t->name == s) {
                if (t->next == t)
                    head = NULL;
                else {
                    t->prev->next = t->next;
                    t->next->prev = t->prev;
                    if (t == head) head = t->next;
                }
                delete t;
                return;
            }
            t = t->next;
        } while (t != head);
    }

    void display() {
        if (!head) {
            cout << "Circle is Empty" << endl;
            return;
        }

        Node* t = head;
        do {
            cout << t->name << " ";
            t = t->next;
        } while (t != head);
        cout << endl;
    }
};

int main() {
    Circular c;

    cout << "Students join: A B C D" << endl;
    c.join("A");
    c.join("B");
    c.join("C");
    c.join("D");
    c.display();

    cout << "C leaves:" << endl;
    c.leave("C");
    c.display();

    cout << "A leaves:" << endl;
    c.leave("A");
    c.display();

    cout << "E joins:" << endl;
    c.join("E");
    c.display();

    return 0;
}