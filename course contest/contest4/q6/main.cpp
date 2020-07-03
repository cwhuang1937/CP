#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int dp[2][3001];
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(s1[i-1] == s2[j-1])
                dp[1][j] = dp[0][j-1] + 1;
            else
                dp[1][j] = max(dp[0][j], dp[1][j-1]);
        }
        for(int j = 1; j <= n; ++j)
            dp[0][j] = dp[1][j];
    }
    cout << dp[0][n] << "\n";
    return 0;
}