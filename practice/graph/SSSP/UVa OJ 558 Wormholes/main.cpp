#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct edge {
    int u, v, w;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n, m, u, v, w;
    
    cin >> t;
    while(t--) {     
        cin >> n >> m;
        edge E[m];
        ll cost[n];
        memset(cost, 0x3f, sizeof cost);
        cost[0] = 0;
        
        for(int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            E[i] = {u, v, w};
        }
        for(int i = 0 ; i < n-1; ++i) {
            for(auto e : E)
                cost[e.v] = min(cost[e.v], cost[e.u] + e.w);
        }
        bool f = 0;
        for(auto e : E) {
           if(cost[e.u] + e.w < cost[e.v]) {
               f = 1;
               break;
           }
        }
        if(f)
            cout << "possible\n";
        else
            cout << "not possible\n";            

    }
    return 0;
}