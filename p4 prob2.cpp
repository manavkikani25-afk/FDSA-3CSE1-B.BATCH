#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> q;
    int n;
    cout << "Enter number of patients: ";
    cin >> n;
    cout << "Enter patient tokens:" << endl;
    for(int i = 0; i < n; i++){
        int x;
        cout << "Enter token " << i + 1 << ": ";
        cin >> x;
        q.push_back(x);
    }
    int value;
    cout << "Enter token to delete: ";
    cin >> value;
    bool found = false;
    for(int i = 0; i < q.size(); i++){
        if(q[i] == value){
            q.erase(q.begin() + i);
            found = true;
            break;
        }
    }
    if(found){
        cout << "Token deleted successfully." << endl;
    }
    else{
        cout << "Token not found." << endl;
    }
    cout << "Queue from front to back: ";
    for(int i = 0; i < q.size(); i++){
        cout << q[i] << " ";
    }
    cout << endl;
    cout << "Queue from last to first: ";
    for(int i = q.size() - 1; i >= 0; i--){
        cout << q[i] << " ";
    }
    cout << endl;
    return 0;
}