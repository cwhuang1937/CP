#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int a[8] = {0};
int dp[8] = {0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for(int i = 1 ; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i) {
        dp[i] = a[i];
        for(int j = 1; j < i; ++j) {
            if(a[i] >= a[j] && dp[j] + a[i] >= dp[i]) {
                dp[i] = dp[j] + a[i];
            }
        }
    }
    // for(int i = 1; i <= n; ++i) {
    //     cout << dp[i] << " ";
    // }
    cout << *max_element(dp, dp + n) << "\n";

    return 0;
}