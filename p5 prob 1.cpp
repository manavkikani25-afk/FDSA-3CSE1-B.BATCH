#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};
class Playlist {
    Node* head;
    Node* tail;
public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }
    void addBeginning(string s) {
        Node* n = new Node(s);
        if (head == NULL) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }
    void addEnd(string s) {
        Node* n = new Node(s);
        if (head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
    void insertAfter(string given, string s) {
        Node* temp = head;
        while (temp != NULL && temp->song != given)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Song not found: " << given << endl;
            return;
        }
        Node* n = new Node(s);
        n->next = temp->next;
        n->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = n;
        else
            tail = n;

        temp->next = n;
    }
    void removeFirst() {
        if (head == NULL)
            return;

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
    }
    void display() {
        Node* temp = head;
        cout << "Playlist: ";
        while (temp != NULL) {
            cout << temp->song << " ";
            temp = temp->next;
        }
        cout << endl;
        cout << "Number of songs: " << count() << endl;
    }
    int count() {
        int c = 0;
        Node* temp = head;
        while (temp != NULL) {
            c++;
            temp = temp->next;
        }
        return c;
    }
};
int main() {
    Playlist p;

    cout << "Adding song at beginning: Song A" << endl;
    p.addBeginning("Song A");
    p.display();

    cout << "Adding song at end: Song C" << endl;
    p.addEnd("Song C");
    p.display();

    cout << "Adding song at beginning: Song B" << endl;
    p.addBeginning("Song B");
    p.display();

    cout << "Inserting Song D after Song B" << endl;
    p.insertAfter("Song B", "Song D");
    p.display();

    cout << "Removing first song" << endl;
    p.removeFirst();
    p.display();

    cout << "Trying to insert Song E after Song X" << endl;
    p.insertAfter("Song X", "Song E");
    p.display();

    return 0;
}