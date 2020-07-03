#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n, a, b;
    double d;
    cin >> t;
    for(int l = 0; l < t; ++l) {
        if(l != 0)
            cout << "\n";
        cin >> n;
        vector<pair<int, double>> V(n);
        for(int i = 0; i < n; ++i) {
            cin >> a >> b;
            d = (double)b/a;
            V[i] = make_pair(i+1, d);
        }
        sort(V.begin(), V.end(), [](pair<int, double> A, pair<int, double> B){return A.second > B.second;});
        for(int i = 0; i < n-1; ++i)
            cout << V[i].first << " ";
        cout << V[n-1].first << "\n";
    }
    return 0;
}