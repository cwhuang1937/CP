#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

#define mxN 100005
ll BIT[mxN];
ll n;

void update(ll x, ll v){
    while(x <= n) {
        BIT[x] += v;
        x += x & -x;
    }
}

ll query(int x) {
    ll res = 0;
    while(x) {
        res += BIT[x];
        x -= x & -x;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int t = 1;
    while(cin >> n) {
        if(n == 0)
            break;
        memset(BIT, 0, sizeof BIT);

        vector<int> a(n), b;
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        // discretization
        b = a;
        sort(b.begin(), b.end());
        unique(b.begin(), b.end());
        for(auto &i : a)
            i =  lower_bound(b.begin(), b.end(), i) - b.begin() + 1;
        
        ll res = 0;
        for(int i = 0; i < n; ++i) {
            res += i - query(a[i]);
            update(a[i], 1);
        }   

        cout << "Case #" << t++ << ": " << res << "\n";
    }
    return 0;
}