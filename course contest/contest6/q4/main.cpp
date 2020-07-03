#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll t, res;
    ld b, tmp;
    cin >> t;
    while(t--) {
        int c = 31;
        cin >> b;
        ld a = 1.0;
        while(c--)
            a *= 1.1;

        // printf("%.15llf\n", a);
        b = b/2.0;
        tmp = a*b;

        // tmp = tmp*1.00000000000001;
        if(tmp - int(tmp) <= 1e-7)
            res = (int)tmp;
        else
            res = (int)tmp + 1;

        // tmp = a * b * 10000000000;
        // res = (int)tmp + 1;
        // res /= 10000000000;
        // tmp /= 10000000000;
        
        cout << res << "\n";
    }
    return 0;
}