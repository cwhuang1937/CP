#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int t, a, b, c, d, x, y, x1, y1, x2, y2;
    cin >> t;

    while(t--) {
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
        if(b-a > x2-x || a-b > x-x1 || d-c > y2-y || c-d > y-y1)
            cout << "No\n";
        else if(x1 == x2 && (a > 0 || b > 0))
            cout << "No\n";
        else if(y1 == y2 && (c > 0 || d > 0))
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}