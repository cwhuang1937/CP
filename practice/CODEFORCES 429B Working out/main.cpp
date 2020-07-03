#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


ll ar[1010][1010] = {0};
ll dp1[1010][1010] = {0};
ll dp2[1010][1010] = {0};
ll dp3[1010][1010] = {0};
ll dp4[1010][1010] = {0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;

    ll n, m;    
    cin >> n >> m;
    for(ll i=1; i<=n; ++i) {
        for (ll j=1; j<=m; ++j) {
            cin >> ar[i][j];
        }
    }

    for(ll i=1; i<=n; ++i)
        for (ll j=1; j<=m; ++j)
            dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + ar[i][j];
    for(ll i=n; i>=1; --i)
        for (ll j=m; j>=1; --j)
            dp2[i][j] = max(dp2[i+1][j], dp2[i][j+1]) + ar[i][j];

    for(ll i=n; i>=1; --i)
        for (ll j=1; j<=m; ++j)
            dp3[i][j] = max(dp3[i][j-1], dp3[i+1][j]) + ar[i][j];
    for(ll i=1; i<=n; ++i)
        for (ll j=m; j>=1; --j)
            dp4[i][j] = max(dp4[i][j+1], dp4[i-1][j]) + ar[i][j];

    ll best = 0;
    for (ll i = 2; i < n; ++i)
        for (ll j = 2; j < m; ++j) {
            best = max({best, dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1],
                        dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j]});
        }
        

    cout << best << "\n";
    return 0;
}