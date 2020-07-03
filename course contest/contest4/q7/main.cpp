#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
using namespace std;

int dp[101][101];
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    memset(dp, 0x3f, sizeof dp);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(i == j) {
                dp[i][j] = 1;
            }
            else {
                for(int k = 1; k <= i; ++k)
                    dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j]);
                for(int k = 1; k <= j; ++k)
                    dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k]);
            }
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}