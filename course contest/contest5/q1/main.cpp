#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll gcd(ll a, ll b)
  { return a? gcd(b%a, a) : b; }
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    vector<ll> V1, V2;

    ll s1 = 0, s2 = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        if(i%2 == 0) {
            V1.push_back(i);
            s1 += i;
        }
        else{
            V2.push_back(i);
            s2 += i;
        }
    }
    if(gcd(s1, s2) == 1)
        cout << "No\n";
    else {
        // cout << s1 << " " << s2 << "\n";
        cout << "Yes\n";
        cout << V1.size() << " " << V2.size() << "\n";
        for(auto i : V1)
            cout << i << " ";
        cout << "\n";
        for(auto i : V2)
            cout << i << " ";
        cout << "\n";
    }
    // cout << gcd(s1, s2) << "\n";
    return 0;
}