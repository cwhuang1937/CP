#include<bits/stdc++.h>
// #include<string.h>
using namespace std;

int t;

int main() {
    cin >> t;
    while(t--) {
        int len, time = 0;
        string s;
        vector<int> V;
        cin >> len >> s;

        for(int i=0; i<len; ++i) {
            if(s[i] == 'A')
                V.push_back(i);
        }
        if(V.size() != 0) {
            for(int i=0; i<V.size()-1; ++i) 
                time = max(time, V[i+1] - V[i]);
            time = max(time, len - V.back());

            cout << time - 1 << '\n';
        } 
        else
            cout << 0 << '\n';
    }
    
    return 0;
}