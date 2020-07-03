#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define MP make_pair
#define F first
#define S second
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n, a, b, c, d;
    cin >> t;
    for(int l = 0; l < t; ++l) {
        if(l != 0)
            cout << "\n";
        cin >> n;
        int res = 0, idx = 0;
        vector<int> V(n);
        queue<pair<int, int>> out;
        for(int i = 0; i < n; ++i) {
            cin >> V[i];
        }
        if(n == 1) {
            cout << V[0] << "\n";
            cout << V[0] << "\n";
            continue;
        }
        sort(V.begin(), V.end(), greater<int>());
        a = V[n-1];
        b = V[n-2];
        if(n == 2) {
            cout << b << "\n";
            cout << a << " " << b << "\n";
            continue;
        }
        while(idx != n-2) {
            d = V[idx++];
            if(idx == n-2)
                break;
            c = V[idx++];
            // A > B > X > Y
            // 1. (AB去) + (A折返) + (XY去) + (B折返) → AB與手電筒會留在原岸，XY已過橋
            // 2. (AY去) + (A折返) + (AX去) + (A折返) → AB與手電筒會留在原岸，XY已過橋
            if(b+a+d+b <= d+a+c+a) {
                res += b+a+d+b;
                out.push(MP(a, b));
                out.push(MP(a, 0));
                out.push(MP(c, d));
                out.push(MP(b, 0));
            }
            else {
                res += d+a+c+a;
                out.push(MP(a, d));
                out.push(MP(a, 0));
                out.push(MP(a, c));
                out.push(MP(a, 0));
            }
        }
        if(n%2 == 0) {
            out.push(MP(a, b));
            res += b;
        }
        else{
            out.push(MP(a, b));
            out.push(MP(a, 0));
            out.push(MP(a, d));
            res += b+a+d;
        }
        cout << res << "\n";
        while(!out.empty()) {
            if(out.front().S != 0)
                cout << out.front().F << " " << out.front().S << "\n";
            else
                cout << out.front().F << "\n";
            out.pop();
        }
    }
    return 0;
}