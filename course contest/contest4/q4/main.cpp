#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

bool mark[1000001];
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> k;
        mark[k] = 1;
    }
    ll res = 0;
    for(int i = n; i > 1; --i) {
        if(mark[i]) {
            res++;
            mark[i/2] = 1;
        }
    }
    cout << res << "\n";
    return 0;
}