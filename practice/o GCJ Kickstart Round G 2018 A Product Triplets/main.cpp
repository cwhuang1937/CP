#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    ll t, n;
    cin >> t;
    for(ll k = 1; k <= t; ++k) {
        cin >> n;
        vector<ll> V(n);
        for(ll i = 0; i < n; ++i)
            cin >> V[i];
        
        sort(V.begin(), V.end());
        ll ans = 0;

        for(ll i = 0; i < n-1; ++i) {
            for(ll j = i+1; j < n; ++j) {
                ll c = V[i]*V[j];
                if(c != 0 || !V[j]) {
                    ans += upper_bound(V.begin()+j+1, V.begin()+n, c) - lower_bound(V.begin()+j+1, V.begin()+n, c);
                }
                else {
                    ans += upper_bound(V.begin()+j+1, V.begin()+n, 0) - lower_bound(V.begin()+j+1, V.begin()+n, 0);
                }
            }
        }
        cout << "Case #" << k << ": " << ans << "\n";
    }
    return 0;
}