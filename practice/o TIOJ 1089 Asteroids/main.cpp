#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int n, k, r, c, vis[505], g[505][505], a[505];

bool dfs(int x) {
    for(int i = 1; i <= n; ++i) {
        if(g[x][i] && !vis[i]) {
            vis[i] = 1;
            if(!a[i] || dfs(a[i])) {
                a[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int res = 0;
    cin >> n >> k;
    while(k--) {
        cin >> r >> c;
        g[r][c] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof vis);
        if(dfs(i))
            res++;
    }
    cout << res << "\n";
    return 0;
}