#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int g[10001];
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

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, u, v, w;
    while(cin >> n >> m) {
        if(n == 0)
            break;

        int cnt = 0;
        ll res = 0;
        vector<edge> E;
        for(int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            E.push_back({u, v, w});
        }
        for(int i = 1; i <= n; ++i)
            g[i] = i;
        
        sort(E.begin(), E.end(), [](edge a, edge b){return a.w < b.w;});

        for(auto e : E) {
            if(Find(e.u) != Find(e.v)) {
                Union(e.u, e.v);
                res += e.w;
                cnt++;
            }
        }
        if(cnt != n-1)
            cout << -1 << "\n";
        else
            cout << res << "\n";
    }
    return 0;
}