#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int MAXN = 1001;
const int MOD = (int)1e9 + 9;
ll dp[MAXN][MAXN] = {0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    dp[1][1] = dp[2][1] = 1;
    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= min(i, k); ++j) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1]) % MOD;
        }
    }
    ll total = 0;
    for(int i = 1; i <= k; ++i)
        total += dp[n][i];

    cout << total % MOD << "\n";

    return 0;
}