#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> V(n);
    for(int i = 0; i < n; ++i)
        cin >> V[i];

    sort(V.begin(), V.end(), greater<int>());
    ll res = 0;
    ll cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(cnt == k-1 && i != n) {
            cnt = 0;
            continue;
        }
        res += V[i];
        cnt++;
    }
    cout << res << "\n";
    return 0;
}