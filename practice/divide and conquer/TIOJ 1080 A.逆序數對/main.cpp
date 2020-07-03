#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll a[100010];

ll count(ll l, ll r) {
    if(r-l == 1)
        return 0;

    ll m = (r+l)/2;
    ll cnt = 0;
    cnt += count(l, m);
    cnt += count(m, r);
    
    ll len = r-l;
    vector<ll> V(len);

    ll idxl = l, idxr = m;
    for(ll i = 0; i < len; ++i) {
        if(idxl < m && idxr < r && a[idxr] < a[idxl]) {
            // cout << idxl << " " << idxr << "\n";
            V[i] = a[idxr++];
            cnt += m-idxl;
        }
        else if(idxl >= m)
            V[i] = a[idxr++];
        else
            V[i] = a[idxl++];

    }

    copy(V.begin(), V.end(), a+l);
    return cnt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    

    ll n, idx = 1;
    while(cin >> n) {
        if(n == 0)
            break;
        
        for(ll i = 0; i < n; ++i)
            cin >> a[i];
        
        cout << "Case #" << idx++ << ": " << count(0, n) << "\n";
    }
    return 0;
}