#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int a[1000005];
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < m; ++i)
        cin >> a[i];
    ll l = 2;
    ll r = n+1;
    ll mid, last;

    while(r >= l) {
        mid = (l+r)/2;
        for(int i = 0; i < k; ++i) {
            
        }
    }
    return 0;
}