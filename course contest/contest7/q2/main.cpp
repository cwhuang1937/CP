#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

#define mxN 100005
ll BIT[mxN];
ll n, m;

void update(ll x, ll v){
    while(x <= n) {
        BIT[x] ^= v;
        x += x & -x;
    }
}

ll query(int x) {
    ll res = 0;
    while(x) {
        res ^= BIT[x];
        x -= x & -x;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    memset(BIT, 0, sizeof BIT);
    cin >> n >> m;
    
    ll a[n+1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i) {
        update(1, a[i]);
    }   
    while(m--) {
        int c, d;
        cin >> c >> d;
        if(c == d)
            cout << a[c] << "\n";
        else
            cout << (query(d) ^ query(c-1)) << "\n";
    }

    return 0;
}