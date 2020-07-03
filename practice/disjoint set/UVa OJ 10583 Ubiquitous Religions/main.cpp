#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int g[50010], res;

int Find(int a) {
    if(g[a] == a)
        return a;
    return g[a] = Find(g[a]);
}
void Union(int a, int b) {
    int ga = Find(a);
    int gb = Find(b);
    if(ga != gb) {
        res--;
        g[ga] = gb;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m, idx = 1, a, b;
    while(cin >> n >> m) {
        if(n == 0)
            break;
        // if(idx != 1)
        //     cout << "\n";
        res = n;
        for(int i = 1; i <= n; ++i)
            g[i] = i;
        
        while(m--) {
            cin >> a >> b;
            Union(a, b);
        }
        
        
        cout << "Case " << idx++ << ": " << res << "\n";  
    }

    return 0;
}