#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    set<ll> S;

    if(n > k) {
        if(n%k == 0) {
            cout << 0 << "\n";
            return 0;
        }
        n = n%k;
        cout << k - n << "\n";

    }
    else {
        while(1) {
            n = min(n, abs(n-k));
            if(S.count(n)) {
                cout << n << "\n";
                break;
            }
            S.insert(n);
        }
    }
    
    
    
    return 0;
}