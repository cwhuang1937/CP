#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        bool odd = false;
        bool even = false;
        cin >> n;
        for(int i = 0; i < n; ++i){
            int input;
            cin >> input;
            if(input%2 == 0)
                even = true;
            else
                odd = true;
        }
        if(even && odd)
            cout << "NO\n";
        else
            cout << "YES\n";

    }
    return 0;
}