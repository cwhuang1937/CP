#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int g[10005];
int Find(int a) {
    if(a == g[a])
        return a;
    return g[a] = Find(g[a]);
}
void Union(int a, int b) {
    g[Find(a)] = Find(b);
}

struct edge {
    int u, v, w;
};
vector<edge> E;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m, u, v, w;
    ll res = 0, total = 0;
    cin >> n >> m;
    
    while(m--) {
        cin >> u >> v >> w;
        E.push_back({u, v, w});
        total += w;
    }
    for(int i = 1; i <= n; ++i)
        g[i] = i;
    sort(E.begin(), E.end(), [](edge a, edge b){return a.w > b.w;});
    
    
    for(auto e : E) {
        if(Find(e.u) != Find(e.v)) {
            Union(e.u, e.v);
            res += e.w;
        }
    }
    cout << total - res << "\n";
    

    return 0;
}
