#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll BIT[100010];
int n;

void update(int x, ll v) {
    while(x <= n) {
        BIT[x] = max(BIT[x], v);
        x += x & -x;
    }
}
ll query(int x) {
    ll res = 0;
    while(x) {
        res = max(res, BIT[x]);
        x -= x & -x;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    vector<int> a(n), b(n);
    memset(BIT, 0, sizeof BIT);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    unique(b.begin(), b.end());
    for(auto &i : a)
        i = lower_bound(b.begin(), b.end(), i) - b.begin() + 1;
    
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        ll val = query(a[i]-1) + 1;
        // cout << val << "\n";
        update(a[i], val);
    }
    res = query(n);
    cout << res << "\n";

    
    return 0;
}