#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    bool f = 1;
    for(ll x = 0; x <= 45000000; ++x) {
        ll tmp = c-x*a;
        if(tmp%b == 0) {
            f = 0;
            cout << "Y\n";
            cout << x << " " << tmp/b << "\n";
            break;
        }
    }
    if(f)
        cout << "N\n";


    return 0;
}