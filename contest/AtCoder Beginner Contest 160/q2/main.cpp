#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int x;
    cin >> x;

    cout << x/500*1000 + x%500/5*5 << "\n";

    return 0;
}