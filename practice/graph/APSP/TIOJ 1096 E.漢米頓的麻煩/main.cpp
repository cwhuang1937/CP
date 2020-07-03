#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    while(cin >> n) {
        if(n == 0)
            break;
        int G[n][n], dist;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                cin >> dist;
                if(dist != 0)
                    G[i][j] = dist;
                else
                    G[i][j] = INT_MAX/2;
            }

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
        
        int res = INT_MAX;
        for(int i = 0; i < n; ++i)
            if(G[i][i] != INT_MAX/2)
                res = min(res, G[i][i]);

        if(res == INT_MAX)
            cout << -1 << "\n";
        else
            cout << res << "\n";

        // for(int i = 0; i < n; ++i) {
        //     for(int j = 0; j < n; ++j)
        //         cout << G[i][j] << " ";
        //     cout << "\n";
        // }
    }
    return 0;
}