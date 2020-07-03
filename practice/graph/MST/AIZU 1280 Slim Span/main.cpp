#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct edge {
    int u, v, w;
};

int g[105];

int Find(int a) {
    if(a == g[a])
        return a;
    return g[a] = Find(g[a]);
}
void Union(int a, int b) {
    g[Find(a)] = Find(b);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, u, v, w;
    while(cin >> n >> m) {
        if(n == 0)
            break;
        vector<edge> E(m);

        for(int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            E.push_back({u, v, w});
        }
        sort(E.begin(), E.end(), [](edge a, edge b){return a.w < b.w;});
        int res = INT_MAX;
        for(int i = 0; i < E.size(); ++i) {
            int start = 0;
            int end = 0;
            int cnt = 0;
            for(int j = 1; j <= n; ++j)
                g[j] = j;
            
            for(int j = i; j < E.size(); ++j) {
                if(j == i)
                    start = E[i].w;
                edge e = E[j];
                if(Find(e.u) != Find(e.v)) {
                    Union(e.u, e.v);
                    end = e.w;
                    cnt++;
                }
            }
            if(cnt != n-1)
                break;
            res = min(res, end-start);
        }
        if(res == INT_MAX)
            cout << -1 << "\n";
        else
            cout << res << "\n";
    }
    return 0;
}