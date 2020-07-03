#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    ll n;
    vector<int> V;
    cin >> n;
    if(n == 1) {
        cout << 1 << "\n";
        return 0;
    }
    while(1) {
        if(n == 1) {
            break;
        }
        bool f = 0;
        for(int j = 9; j >= 2; --j) {
            if(n % j == 0) {
                n /= j;
                V.push_back(j);
                f = 1;
                break;
            }
        }
        // cout << n << "\n";
        if (!f) {
            cout << -1 << "\n";
            return 0;
        }
    }
    reverse(V.begin(), V.end());
    for(auto e : V)
        cout << e;
    cout << "\n";
    return 0;
}