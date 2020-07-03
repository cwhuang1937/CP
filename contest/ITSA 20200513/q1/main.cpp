#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    double a, b, c, d, e, f;
    cin >> a >> b >> c;
    printf("%.2lf\n", (a+b)/c);
    for(int i = 0; i < 9; ++i) {
        cin >> a >> b >> c >> d >> e >> f;
        printf("%.3lf\n", (a+b+c)/(d+b+e+c) + f/d);
    }
    return 0;
}