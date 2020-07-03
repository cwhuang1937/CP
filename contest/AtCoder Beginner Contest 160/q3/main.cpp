#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int k, n;
    cin >> k >> n;

    vector<int> V(n), D(n);
    for(int i = 0; i < n; ++i)
        cin >> V[i];

    for(int i = 0; i < n-1; ++i)
        D[i] = V[i+1] - V[i];
    D[n-1] = k - V[n-1] + V[0];

    ll total = 0;
    for(int i = 0; i < n; ++i)
        total += D[i];
    cout << total - *max_element(D.begin(), D.end()) << "\n";
    
    return 0;
}