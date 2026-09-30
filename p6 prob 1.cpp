#include <iostream>
using namespace std;

int main() {
    int stack[5], top = -1;

    cout << "Stack Capacity: 5" << endl;

    cout << "Place: 10" << endl;
    if (top < 4) stack[++top] = 10;
    else cout << "Error: Stack is Full" << endl;
    cout << "Top: " << stack[top] << endl;

    cout << "Place: 20" << endl;
    if (top < 4) stack[++top] = 20;
    cout << "Top: " << stack[top] << endl;

    cout << "Place: 30" << endl;
    if (top < 4) stack[++top] = 30;
    cout << "Top: " << stack[top] << endl;

    cout << "Take" << endl;
    if (top >= 0) top--;
    else cout << "Error: Stack is Empty" << endl;
    cout << "Top: " << (top >= 0 ? stack[top] : -1) << endl;

    cout << "Take" << endl;
    if (top >= 0) top--;
    else cout << "Error: Stack is Empty" << endl;
    cout << "Top: " << (top >= 0 ? stack[top] : -1) << endl;

    return 0;
}