#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> V(n, 0);

    for(int i = 1; i <= n-1; ++i) {
        for(int j = i+1; j <= n; ++j) {
            int d = min(j-i, abs(x-i) + 1 + abs(y-j));
            V[d]++;
        }
    }
    for(int i = 1; i <= n-1; ++i)
        cout << V[i] << "\n";
    
    return 0;
}