#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    ll n;
    cin >> n ;
    vector<ll> V;
    map<ll, ll> M;
    for (ll i = 0; i < n; ++i) {
        ll num;
        cin >> num;
        V.push_back(num);
        M[num]++;
    }
    ll total = 0;
    for(auto it = M.begin(); it != M.end(); ++it) {
        ll k = it->second;
        total += k * (k - 1) / 2;      
    }
    for (ll i = 0; i < n; ++i) {
        ll k = M[V[i]];
        cout << total - (k-1) << "\n";
    }
    return 0;
}