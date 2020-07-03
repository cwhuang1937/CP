#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int a[8];
int dp[8];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i)
        dp[i] = max(dp[i - 1], dp[i - 1] + a[i]);

    // for(int i = 1; i <= n; ++i)
    //     cout << dp[i] << " ";
    cout << dp[n] << "\n";

    return 0;
}