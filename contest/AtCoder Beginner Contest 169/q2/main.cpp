#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    ll res = 1;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    if(a[0] == 0) {
        cout << 0 << "\n"; 
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        ll tmp = res;
        res *= a[i];
        cout << res << "\n";
        if(res > 1000000000000000000 || res < tmp) {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << res << "\n";

    return 0;
}