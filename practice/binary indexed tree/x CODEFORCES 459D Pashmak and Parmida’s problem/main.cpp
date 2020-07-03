#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int n;
ll a[1000010];
ll bit[1000010];

void update(int idx, int val) {
    while(idx <= n) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}
ll query(int idx) {
    ll res = 0;
    while(idx) {
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];


    
    return 0;
}