#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n, num;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> V(n), ans;
        for(int i = 0; i < n; ++i)
            cin >> V[i];

        int cnt = 0;
        for(int i = 1; i < n; ++i) {
            set<int> S1, S2;
            for(int j = 0; j < i; ++j) {
                S1.insert(V[j]);
                cout << V[j] << "\n";
            }
            cout << *S1.begin() << " " << *S1.end() << "\n";
            if(S1.size() != i || *S1.begin() != 1 || *S1.end() != i)
                continue;
            for(int j = i; j < n; ++j) {
                S2.insert(V[j]);
            }
             
            if(S2.size() != 5-i || *S2.begin() != 1 || *S2.end() != 5-i)
                continue;
            // cout << "???\n";  
            cnt++;
            ans.push_back(i);
        }
        cout << cnt << "\n";
        for(auto i:ans) {
            cout << i << " " << 5-i << "\n";
        }
    }
    return 0;
}