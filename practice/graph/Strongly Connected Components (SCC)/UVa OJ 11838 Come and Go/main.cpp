#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

vector<int> g[2005], gr[2005];
vector<int> order, comp;
bool vis[2005];

void dfs1(int u) {
    vis[u] = 1;
    for(auto v : g[u])
        if(!vis[v])
            dfs1(v);
    order.push_back(u);
}
void dfs2(int u) {
    vis[u] = 1;
    comp.push_back(u);
    for(auto v: gr[u])
        if(!vis[v])
            dfs2(v);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, u, v, c;
    while(cin >> n >> m) {
        if(n == 0)
            break;
        for(int i = 1; i <= n; ++i) {
            g[i].clear();
            gr[i].clear();
        }
        order.clear();
        comp.clear();
        for(int i = 0; i < m; ++i) {
            cin >> u >> v >> c;
            if(c == 1) {
                g[u].push_back(v);
                gr[v].push_back(u);
            }
            else {
                g[u].push_back(v);
                g[v].push_back(u);
                gr[u].push_back(v);
                gr[v].push_back(u);
            }
        }
        for(int i = 1; i <= n; ++i)
            vis[i] = 0;  
        for(int i = 1; i <= n; ++i)
            if(!vis[i])
                dfs1(i);
        reverse(order.begin(), order.end());
        for(int i = 1; i <= n; ++i)
            vis[i] = 0;
        for(auto u : order) {
            if(!vis[u]) {
                dfs2(u);
                if(comp.size() == n)
                    cout << 1 << "\n";
                else
                    cout << 0 << "\n";
                break;
            }
        }

    }

    return 0;
}