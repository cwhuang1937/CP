#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
using namespace std;

pair<int, int> a[2000010];
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, l, r, w;
    cin >> n;
    for(int i = 0; i < 2*n; i+=2) {
        cin >> l >> r >> w;
        a[i].F = l;
        a[i].S = w;
        a[i+1].F = r;
        a[i+1].S = -w;
    }
    sort(a, a + 2*n);
    // for(int i = 0; i < 2*n; ++i) {
    //     cout << a[i].F << " " << a[i].S << "\n";
    // }
    ll res = 0, temp = 0;
    for(int i = 0; i < 2*n; ++i) {
        temp += a[i].S;
        res = max(res, temp);
    }
    cout << res << "\n";
    return 0;
}