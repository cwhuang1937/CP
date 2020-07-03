#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        if(n % 2 == 0) {
            if(k % 2 == 0) {
                ll sum = 0;
                bool f = false;
                for (ll i = 0; i < k; ++i) {
                    sum = sum + 1 + 2 * i;
                    if(sum > n) {
                        cout << "NO\n";
                        f = true;
                        break;
                    }
                }
                if(!f)  
                    cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
        else {
            if(k % 2 == 0)
                cout << "NO\n";
            else {
                ll sum = 0;
                bool f = false;
                for (ll i = 0; i < k; ++i) {
                    sum = sum + 1 + 2 * i;
                    if(sum > n) {
                        cout << "NO\n";
                        f = true;
                        break;
                    }
                }     
                if(!f)    
                    cout << "YES\n";
            }
        }
    }
    return 0;
}