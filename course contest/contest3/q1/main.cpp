#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll dp[101][105][105];
int mod = 48763;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> m >> n;
    memset(dp, 0, sizeof dp);
    dp[1][1][m] = 1;
    for(int i = 1; i <= 100; ++i) {
        if(i == 74)
            continue;
        for(int j = 1; j <= n; ++j) {
            for(int k = m; k >= 1; --k) {
                if(k != m && i >= 2) {
                    dp[i][j][k] += dp[i-1][j][k+1];
                    dp[i][j][k] %= mod;
                }
                if(i >= 3) {
                    dp[i][j][k] += dp[i-2][j][k];
                    dp[i][j][k] %= mod;
                }
                if(i != 100) {
                    dp[i][j][k] += dp[i][j-1][k] + dp[i][j][k+1];
                    dp[i][j][k] %= mod;
                }
            }
        }      
    }

    ll res = 0;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= m; ++j) {
            res += dp[100][i][j];
            res %= mod;
        }
    cout << res << "\n";
    return 0;
}