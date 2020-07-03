// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<string.h>
#define ll long long
#define ld long double
using namespace std;

double log2(double d) {
    return log(d)/log(2.0);
}
vector<int> E[10005];
int dep[10005], vis[10005], an[10005][20];
void dfs(int u, int d) {
    vis[u] = 1;
    dep[u] = d;
    for(int j = 0; j < E[u].size(); ++j) {
        int v = E[u][j];
        if(!vis[v]) {
            an[v][0] = u;
            for(int i = 1; i <= log2(d+1); ++i) {
                an[v][i] = an[an[v][i-1]][i-1];
            }
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
    int t, n, u, v, root;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            E[i].clear();
            vis[i] = 0;
            for(int j = 0; j < 20; ++j)
                an[i][j] = 0;
        }

        root = 0;
        int g[10005];
        memset(g, 0, sizeof g);
        for(int i = 0; i < n-1; ++i) {
            cin >> u >> v;
            E[u].push_back(v);
            E[v].push_back(u);
            g[v] = u;
        }
        for(int i = 1; i <= n; ++i) {
            if(!g[i]) {
                root = i;
                break;
            }
        }
        cin >> u >> v;
        dfs(root, 0);
        cout << LCA(u, v) << "\n";
    }

    return 0;
}