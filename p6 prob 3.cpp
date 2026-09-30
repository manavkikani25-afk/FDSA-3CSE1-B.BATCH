#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s = "(3+4)*2";
    stack<char> st;
    string post = "";

    cout << "Infix: " << s << endl;

    for (char c : s) {
        if (isalnum(c))
            post += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')') {
            while (st.top() != '(') {
                post += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && st.top() != '(') {
                post += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        post += st.top();
        st.pop();
    }

    cout << "Postfix: " << post << endl;

    return 0;
}