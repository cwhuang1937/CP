#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int t, n, p;
    cin >> t;
    while(t--) {
        cin >> n >> p;
        vector<int> V(p); // record the hartal parameter
        ll res = 0; // store the result
        for(int i = 0; i < p; ++i) // reading input
            cin >> V[i];
        
        for(int i = 1; i <= n; ++i) {
            if(i%7 == 0 || i%7 == 6) // exclued the Friday and Saturstay
                continue;
            for(int j = 0; j < V.size(); ++j) {
                if(i%V[j] == 0) { // hartals day for add one to the result
                    res++;
                    break;
                }
            }
        }
        cout << res << "\n"; // output the result
    }

    return 0;
}