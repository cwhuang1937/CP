#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int k = 1; k <= n; ++k) {
                int t = gcd(i, j);
                res += gcd(t, k);
            }
        }
    }
    cout << res << "\n";
    return 0;
}