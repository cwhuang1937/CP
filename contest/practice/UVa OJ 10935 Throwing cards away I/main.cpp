#include<bits/stdc++.h>
using namespace std;


int main() {
    // int count = 0;
    while(1) {
        int n;
        cin >> n;
        if(n == 0)
            break;
        // if(count != 0){
        //     cout << '\n';
        // }
        // count++;
        queue<int> Q;
        for(int i = 1; i <= n; ++i) {
            Q.push(i);
        }
        if(n == 1){
            cout << "Discarded cards:";
        }
        else {
            cout << "Discarded cards: ";
        }
        for(int i = 0; i < n-1; ++i) {
            cout << Q.front();
            Q.pop();
            Q.push(Q.front());
            Q.pop();
            if(i != n-2)
                cout << ", ";
        }
        cout << "\nRemaining card: " << Q.front() << '\n';
    }
    return 0;
}