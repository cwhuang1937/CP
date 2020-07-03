#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int MOD = 1e9 + 7;

ll power(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y & 1)
            res = x * res % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}
 
int main() {
    int n;
    map<int, int> M;
    cin >> n;
    for(int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        M[tmp]++;
    }
    ll x, y, fp, ans = 1, d = 1;
    for (const auto& pr : M) {
        x = pr.first;
        y = pr.second;
        fp = power(x, y * (y + 1) / 2);
        ans = power(ans, y + 1) * power(fp, d) % MOD;
        d = d * (y + 1) % (MOD - 1);
    }
    cout << ans << "\n";
}