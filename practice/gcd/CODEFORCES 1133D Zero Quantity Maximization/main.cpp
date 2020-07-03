#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, out = 0;
    cin >> n;
    vector<int> a(n), b(n);
    map<ld, ll> M;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    for(int i = 0; i < n; ++i) {
        if(a[i] != 0 && b[i] != 0) {
            M[(ld)b[i]/a[i]]++;
        }
        else if(a[i] != 0 && b[i] == 0) {
            M[0]++;
        }
        else if(a[i] == 0 && b[i] == 0)
            out++;
    }

    ll res = 0;
    for(auto i : M) {
        res = max(res, i.second);
    }
    cout << res + out << "\n";
    
    return 0;
}