#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> pages;
    string current = "Home";

    cout << "Visit: Google" << endl;
    pages.push(current);
    current = "Google";
    cout << "Current Page: " << current << endl;

    cout << "Visit: YouTube" << endl;
    pages.push(current);
    current = "YouTube";
    cout << "Current Page: " << current << endl;

    cout << "Visit: GitHub" << endl;
    pages.push(current);
    current = "GitHub";
    cout << "Current Page: " << current << endl;

    cout << "Back" << endl;
    if (!pages.empty()) {
        current = pages.top();
        pages.pop();
    }
    cout << "Current Page: " << current << endl;

    cout << "Back" << endl;
    if (!pages.empty()) {
        current = pages.top();
        pages.pop();
    }
    cout << "Current Page: " << current << endl;

    cout << "Back" << endl;
    if (!pages.empty()) {
        current = pages.top();
        pages.pop();
    } else
        cout << "No history left" << endl;

    cout << "Current Page: " << current << endl;

    return 0;
}