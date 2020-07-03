#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> V(n);
    for(int i = 0; i < n; ++i)
        cin >> V[i];
    int dp[n][n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            dp[i][j] = INT_MAX;
    for(int i = 0; i < n; ++i)
        dp[i][i] = V[i];


    for(int l = 1; l < n; ++l) {
        for(int i = 0; i+l < n; ++i){
            int j = i+l;
            for(int k = i; k < j; ++k) {
                if(i != k && j != k+1)
                    dp[i][j] = min(dp[i][j], 2*(dp[i][k] + dp[k+1][j]));   
                else if(i == k && j == k+1)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);           
                else if(i == k && j != k+1)
                    dp[i][j] = min(dp[i][j], dp[i][k] + 2*dp[k+1][j]);
                else if(i != k && j == k+1)
                    dp[i][j] = min(dp[i][j], 2*dp[i][k] + dp[k+1][j]);
                // cout << i << " " << k << " " << j <<  " "  << dp[i][j] <<  "\n";
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    cout << dp[0][n-1] << "\n";
    return 0;
}