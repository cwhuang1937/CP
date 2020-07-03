#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int rec[500000];
int vis[500000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m, u, v, w, q, k;
    cin >> n >> m >> q >> k;

    vector<int> E[n+1];
    while(m--) {
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    queue<int> Q;
    Q.push(k);
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(auto v : E[u]) {
            if(vis[v])
                continue;
            vis[v] = 1;
            Q.push(v);
            rec[v] = u;
        }
    }

    while(q--) {
        int tar;
        cin >> tar;
        if(rec[tar] == 0)
            cout << -1 << " ";
        else
            cout << rec[tar] << " ";

    }
    cout << "\n";
    

    return 0;
}