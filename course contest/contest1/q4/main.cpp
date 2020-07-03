#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> V(n);
    for(int i = 0; i < n; ++i)
        cin >> V[i];
    if(k >= m)
        cout << m << "\n";
    else {
        for(int i = 0; i < n-1; ++i)
            V[i] = V[i+1] - V[i];
        
        sort(V.begin(), V.end());
        ll total = 0;
        for(int i = 0; i < n-k; ++i)
            total += V[i];

        cout << total + k << "\n";
    }
    return 0;
}