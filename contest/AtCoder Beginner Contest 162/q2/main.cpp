#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        if(i%3 != 0 && i%5 != 0)
            res += i;
    }
    cout << res << "\n";
    return 0;
}