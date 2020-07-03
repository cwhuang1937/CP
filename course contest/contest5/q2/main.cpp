#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct edge {
    ll u, v, w;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m, u, v, w;

    cin >> n >> m;
    edge E[m];
    ll cost[n];
    memset(cost, 0x3f, sizeof cost);
    cost[0] = 0;
    
    for(ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        E[i] = {u, v, w};
    }
    for(ll i = 0 ; i < n-1; ++i) {
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
        cout << "Yes\n";
    else
        cout << "No\n";
    

    return 0;
}