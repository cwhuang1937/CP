#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

vector<int> E[10010];
int dep[10010], an[10010][30], vis[10010];

void dfs(int u, int d) {
    dep[u] = d;
    vis[u] = 1;
    for(auto v: E[u]) {
        if(!vis[v]) {
            an[v][0] = u;
            for(int i = 1; i <= log2(d+1); ++i)
                if(an[v][i-1] != -1)
                    an[v][i] = an[an[v][i-1]][i-1]; // important !!!!
                    // 要求v跳2^i步的祖先，即v跳2^(i-1)步的祖先再跳2^(i-1)步
            dfs(v, d+1);
        }
    }
}
int LCA(int u, int v) {
    if(dep[u] < dep[v])
        swap(u, v);
    while(dep[u] != dep[v]) { // let dep[u] == dep[v]
        int i = log2(dep[u] - dep[v]);
        u = an[u][i];
    }
    if(u == v)
        return u;
    for(int i = log2(dep[u]); i >= 0; --i) {
        if(an[u][i] != an[v][i]) { // 若u, v一起往上跳會到不同點，故代表還沒跳在一起，因此要從下更新上去
            u = an[u][i];
            v = an[v][i];
        }
    }
    return an[u][0];
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q, u, v;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < 30; ++j)
            an[i][j] = -1;

    for(int i = 1; i <= n-1; ++i) {
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }   
    dfs(1, 0);
    cin >> q;
    for(int i = 0; i < q; ++i) {
        cin >> u >> v;
        if(dep[v] > dep[u]) {
            cout << "NO\n";
            continue;
        }
        cout << "YES " << LCA(u, v) << "\n";
        
    }
    return 0;
}