#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

vector<int> E[110];
int dep[110], low[110], res;

void dfs(int u, int p, int d) {
    dep[u] = low[u] = d;
    int cnt = 0;
    bool isAP = 0;

    for(auto v : E[u]) {
        if(dep[v] == -1) {
            cnt++;
            dfs(v, u, d+1);
            
            low[u] = min(low[u], low[v]);
            if(low[v] >= dep[u])
                isAP = 1;
        }
        else {
            low[u] = min(low[u], dep[v]);
        } 
    }
    if(cnt < 2 && p == -1)
        isAP = 0;
    if(isAP)
        res++; 
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, u, v;
    string s;
    while(cin >> n) {
        if(n == 0)
            break;
        for(int i = 1; i <= n; ++i) {
            E[i].clear();
            dep[i] = -1;
            low[i] = -1;
        }
        res = 0;

        getline(cin, s);
        while(getline(cin, s)) {
            // cout << s << "\n";
            if(s == "0\r" || s == "0")
                break;
            stringstream ss(s);
            ss >> u;
            while(ss >> v) {
                E[u].push_back(v);
                E[v].push_back(u);
            }
        }
        dfs(1, -1, 0);
        cout << res << "\n";
    }
    return 0;
}