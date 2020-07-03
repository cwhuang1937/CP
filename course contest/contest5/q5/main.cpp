#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

vector<int> E[100010];
int dep[100010], an[100010][30], vis[100010];

void dfs(int u, int d) {
    dep[u] = d;
    vis[u] = 1;
    for(auto v: E[u]) {
        if(!vis[v]) {
            an[v][0] = u;
            for(int i = 1; i <= log2(d+1); ++i)
                if(an[v][i-1] != -1)
                    an[v][i] = an[an[v][i-1]][i-1];
            dfs(v, d+1);
        }
    }
}
int LCA(int u, int v) {
    if(dep[u] < dep[v])
        swap(u, v);
    while(dep[u] != dep[v]) {
        int i = log2(dep[u] - dep[v]);
        u = an[u][i];
    }
    if(u == v)
        return u;
    for(int i = log2(dep[u]); i >= 0; --i) {
        if(an[u][i] != an[v][i]) { 
            u = an[u][i];
            v = an[v][i];
        }
    }
    return an[u][0];
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < 30; ++j)
            an[i][j] = -1;

    for(int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }   
    dfs(0, 0);
    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        cout << LCA(u, v) << "\n";
        
    }
    return 0;
}