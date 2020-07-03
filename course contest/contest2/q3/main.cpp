#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int g[100010];

int Find(int a) {
    if(a == g[a])
        return a;
    return g[a] = Find(g[a]);
}
void Union(int a, int b) {
    int ga = Find(a);
    int gb = Find(b);
    if(ga != gb) {
        g[ga] = gb;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m, op, a, b;
    cin >> n >> m;
    unordered_map<int, int> M;
    for(int i = 1; i <= n; ++i) {
        g[i] = i;
    }
    while(m--) {
        cin >> op >> a >> b; 
        
        int ga = Find(a);
        int gb = Find(b);
        if(ga > gb) {
            int t = ga;
            ga = gb;
            gb = t;
        }
        // cout << ga << " " << gb << "\n";
        if(op == 1) {
            if((M.count(ga) && M[ga] == gb) || (M.count(gb) && M[gb] == ga)) {
                
                cout << "nani\n"; 
                continue;
            }
            Union(a, b);
            
        }
        else if (op == 2) {
            if(ga == gb) {
                cout << "nani\n"; 
                continue;
            }

            if(M.count(ga))
                Union(b, M[ga]);
            else {
                M[ga] = b;

            }
            if(M.count(gb))
                Union(a, M[gb]);
            else {
                M[gb] = a;

            }

            
        }
        else {
            // cout << ga << " " << gb << "\n";
            if(ga == gb) {
                cout << "friend\n";
            }
            else if(M[ga] == gb || M[gb] == ga) {
                cout << "ememy\n";
            }
            else {
                cout << "none\n";
            }

            
        }
    }
    return 0;
}