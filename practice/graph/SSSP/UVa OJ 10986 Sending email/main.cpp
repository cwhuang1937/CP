#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct node {
    ll id, w;
    bool operator < (node rhs) const { 
        return w > rhs.w;
    }
};


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int N, n, m, S, T, u, v, w;
    cin >> N;
    for(int k = 1; k <= N; ++k) {
        cin >> n >> m >> S >> T;
        vector<node> E[n];
        ll cost[n];
        memset(cost, 0x3f, sizeof cost);
        cost[S] = 0;
        for(int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            E[u].push_back({v, w});
            E[v].push_back({u, w});
        }
        priority_queue<node> Q;
        Q.push({S, cost[S]});

        while(!Q.empty()) {
            node u = Q.top();
            Q.pop();
            for(auto v : E[u.id]) {
                ll ud = u.w + v.w;
                if(ud < cost[v.id]) {
                    cost[v.id] = ud;
                    Q.push({v.id, cost[v.id]});
                }
            }
        }
        cout << "Case #" << k << ": ";
        if(cost[T] < 1e9)
            cout << cost[T] << "\n";
        else
            cout << "unreachable\n";
    }
    return 0;
}