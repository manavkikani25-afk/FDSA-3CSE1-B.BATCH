#include <iostream>
using namespace std;

struct S {
    string name;
    S *next;
};

struct D {
    string name;
    D *next, *prev;
};

void showS(S *h) {
    S *t = h;
    do {
        cout << t->name << " ";
        t = t->next;
    } while (t != h);
    cout << endl;
}

void showD(D *h) {
    D *t = h;
    do {
        cout << t->name << " ";
        t = t->next;
    } while (t != h);
    cout << endl;
}

int main() {
    S *a = new S{"A", NULL};
    S *b = new S{"B", NULL};
    S *c = new S{"C", NULL};
    a->next = b; b->next = c; c->next = a;

    D *x = new D{"A", NULL, NULL};
    D *y = new D{"B", NULL, NULL};
    D *z = new D{"C", NULL, NULL};
    x->next = y; y->prev = x;
    y->next = z; z->prev = y;
    z->next = x; x->prev = z;

    cout << "Singly: ";
    showS(a);
    cout << "Doubly: ";
    showD(x);

    cout << "B leaves" << endl;

    a->next = c;
    c->next = a;
    delete b;

    x->next = z;
    z->prev = x;
    z->next = x;
    x->prev = z;
    delete y;

    cout << "Singly: ";
    showS(a);
    cout << "Doubly: ";
    showD(x);

    cout << "D joins" << endl;

    b = new S{"D", a};
    c->next = b;
    b->next = a;

    y = new D{"D", x, z};
    z->next = y;
    x->prev = y;
    y->next = x;
    y->prev = z;

    cout << "Singly: ";
    showS(a);
    cout << "Doubly: ";
    showD(x);

    return 0;
}
