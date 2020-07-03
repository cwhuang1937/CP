#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define MP make_pair
#define F first
#define S second
using namespace std;

struct node {
    ll id, w;
    bool operator < (const node &rhs) const { 
        return id > rhs.id; 
    }
};

ll cost[100005];
vector<node> E[100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, u, v, w;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    memset(cost, 0x3f, sizeof cost);
    cost[0] = 0;
    priority_queue<node> Q;
    Q.push({0, 0});

    while(!Q.empty()) { 
        node u = Q.top();
        Q.pop();
        for(auto v : E[u.id]) {
            ll ud = u.w + v.w;
            if(ud < cost[v.id]) {
                cost[v.id] = ud;
                Q.push({v.id, ud});
            }
        }
    }
    for(int i = 0; i < n; ++i)
        cout << cost[i] << " ";
    cout << "\n";
    return 0;
}