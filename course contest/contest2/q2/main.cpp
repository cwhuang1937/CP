#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
#define maxn 1005

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    ll N, k, x;
    cin >> N;
    while(N--) {
        cin >> k >> x;
        cout << (k-1)*9 + x << "\n"; 
    }
    return 0;
}