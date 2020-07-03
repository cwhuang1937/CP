#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k > n) {
            cout << "NO\n";
            continue;
        }
        if(n % k == 0) {
            cout << "YES\n";
            for(int i = 0; i < k-1; ++i) {
                cout << n/k << " ";
            }
            cout << n/k << "\n";
        }
        else {
            if((n-k)%2 == 0) {
                cout << "YES\n";
                for(int i = 0; i < k-1; ++i) {
                    cout << 1 << " ";
                }
                cout << n-k+1 << "\n";
            }
            else if((n-k*2)%2 == 0 && n > 2*k) {
                cout << "YES\n";
                for(int i = 0; i < (k-1); ++i) {
                    cout << 2 << " ";
                }
                cout << (n-k*2)+2 << "\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}