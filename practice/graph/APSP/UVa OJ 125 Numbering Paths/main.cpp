#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int mxN = 1000;
ll G[mxN][mxN];
// int a[mxN][mxN];
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, u, v, idx = 0;
    while(cin >> m) {
        memset(G, 0, sizeof G);
        n = 1;
        for(int i = 0; i < m; ++i) {
            cin >> u >> v;
            G[u][v] = 1;
            n = max({n, u+1, v+1});
        }
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    G[i][j] += G[i][k] * G[k][j];

        for(int k = 0; k < n; ++k) {
            if(!G[k][k])
                continue;
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(G[i][k] && G[k][j])
                        G[i][j] = -1;
        }
        cout << "matrix for city " << idx++ << "\n";
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n-1; ++j)
                cout << G[i][j] << " ";
            cout << G[i][n-1] << "\n";  
        }
    }
    
    return 0;
}