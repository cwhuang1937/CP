#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct node {
    int id, w;
};
struct edge {
    int u, v, w;
    bool operator < (edge a) const {
        return w > a.w; // min heap
    }
};
const int mxN = 1000005;
bool vis[mxN];
vector<node> E[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, u, v, w, M, K;
    bool f = 0;
    while(cin >> n) {
        if(f)
            cout << "\n";
        ll out1 = 0, out2 = 0;
        memset(vis, 0, sizeof vis);
        memset(E, 0, sizeof E);

        for(int i = 0; i < n-1; ++i) {
            cin >> u >> v >> w;
            out1 += w;
        }
        cin >> K;
        for(int i = 0; i < K; ++i) {
            cin >> u >> v >> w;
            E[u].push_back({v, w});
            E[v].push_back({u, w});
        }
        cin >> M;
        for(int i = 0; i < M; ++i) {
            cin >> u >> v >> w;
            E[u].push_back({v, w});
            E[v].push_back({u, w});
        }   
        // cout << n << K << M << "\n";
        priority_queue<edge> Q;
        Q.push({1, 1, 0});
        while(!Q.empty()) {
            edge e = Q.top();
            Q.pop();
            int u = e.v;
            if(vis[u])
                continue;
            vis[u] = 1;
            out2 += e.w;
            for(auto v : E[u]) {
                if(!vis[v.id]) {
                    Q.push({u, v.id, v.w});
                }
            }
        }

        cout << out1 << "\n";
        cout << out2 << "\n";
        f = 1;
    }

    return 0;
}