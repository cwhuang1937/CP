#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n ;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    n--;
    int dp[n+1][n+1];

    for(int i = 1; i <=n; ++i)
        for(int j = 1; j <= n; ++j)
            dp[i][j] = INT_MAX;

    for(int i = 1; i <= n; ++i)
        dp[i][i] = 0;

    for(int i = n; i >= 1; --i) {
        for(int j = i; j <= n; ++j) {
            if(i != j) {
                for(int k = i; k <= j-1; ++k) {
                    int count = dp[i][k] + dp[k+1][j] + a[i-1]*a[k]*a[j];
                    // cout << count  << " " << dp[i][j] << "\n";
                    if(count < dp[i][j]) {
                        dp[i][j] = count;
                    }
                }
            }
        }
    }
    cout << dp[1][n] << "\n";
    // for(int i = 1; i <=n; ++i) {
    //     for(int j = 1; j <= n; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    return 0;
}