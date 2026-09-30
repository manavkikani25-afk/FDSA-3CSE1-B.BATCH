#include <iostream>
using namespace std;

struct Node {
    string song;
    Node *prev, *next;
};

int main() {
    Node *head = NULL, *tail = NULL;

    Node *a = new Node{"Song A", NULL, NULL};
    head = tail = a;
    cout << "Add at beginning: Song A" << endl;

    Node *b = new Node{"Song B", tail, NULL};
    tail->next = b;
    tail = b;
    cout << "Add at end: Song B" << endl;

    Node *c = new Node{"Song C", head, head->next};
    head->next->prev = c;
    head->next = c;
    cout << "Insert Song C after Song A" << endl;

    cout << "Playlist: ";
    Node *t = head;
    int count = 0;
    while (t) {
        cout << t->song << " ";
        count++;
        t = t->next;
    }
    cout << endl << "Count: " << count << endl;

    t = head;
    head = head->next;
    head->prev = NULL;
    delete t;

    cout << "Remove first song" << endl;
    cout << "Playlist: ";
    t = head;
    count = 0;
    while (t) {
        cout << t->song << " ";
        count++;
        t = t->next;
    }
    cout << endl << "Count: " << count << endl;

    return 0;
}
