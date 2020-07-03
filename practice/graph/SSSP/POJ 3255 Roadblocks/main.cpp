// #include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

#define ll long long
#define ld long double
using namespace std;

struct node {
    ll id, w;
    bool operator < (node rhs) const { 
        return w > rhs.w;
    }
};


vector<node> E[100001];
ll cost[5001], cost2[5001];
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m, u, v, w;
    cin >> n >> m;   
    memset(cost, 0x3f, sizeof cost);
    memset(cost2, 0x3f, sizeof cost2);
    cost[1] = 0;
    for(ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        node e1 = {v, w};
        node e2 = {u, w};
        E[u].push_back(e1);
        E[v].push_back(e2);
    }
    priority_queue<node> Q;
    node e = {1, 0};
    Q.push(e);
    while(!Q.empty()) {
        node u = Q.top();
        Q.pop();
        for(ll i = 0; i < E[u.id].size(); ++i) {
            node v = E[u.id][i];
            ll update = u.w + v.w;
            if(update < cost[v.id]) {
                node e = {v.id, update};
                Q.push(e);
                swap(cost[v.id], update);
            }
            if(update < cost2[v.id] && update > cost[v.id]) {
                cost2[v.id] = update;
                node e = {v.id, update};
                Q.push(e);
            }
        }
    }
    cout << cost2[n] << "\n";
    return 0;
}