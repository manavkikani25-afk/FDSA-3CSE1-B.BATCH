#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> q;
    int n;

    cout << "Enter number of operations: ";
    cin >> n;
    cout << endl;

    cout << "Operation types: " << endl;
    cout << "1 = Insert at front" << endl;
    cout << "2 = Insert at end" << endl;
    cout << "3 = Insert at specific position" << endl;

    for(int i = 0; i < n; i++){
        int type, value, pos;
        cout << "Enter operation " << i + 1 << ": ";
        cin >> type;
        if(type == 1){
            cout << "Enter value: ";
            cin >> value;
            q.insert(q.begin(), value);
        }
        else if(type == 2){
            cout << "Enter value: ";
            cin >> value;
            q.push_back(value);
        }
        else if(type == 3){
            cout << "Enter value and position: ";
            cin >> value >> pos;
            if(pos >= 0 && pos <= q.size()){
                q.insert(q.begin() + pos, value);
            }
            else{
                cout << "Invalid position!" << endl;
                continue;
            }
        }
        cout << "Current Queue: ";
        for(int j = 0; j < q.size(); j++){
            cout << q[j] << " ";
        }
        cout << endl << endl;
    }
    cout << "Final Queue: ";
    for(int j = 0; j < q.size(); j++){
        cout << q[j] << " ";
    }
    cout << endl;
    return 0;
}