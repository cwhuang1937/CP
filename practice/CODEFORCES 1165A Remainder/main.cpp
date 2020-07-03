#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x, y, res = 0;;
    string s;
    cin >> n >> x >> y;
    getline(cin, s);
    getline(cin, s);
    reverse(s.begin(), s.end());
    for(int i = 0; i < x; ++i) {
        if(i == y && s[i] == '0')
            res++;
        else if(i != y && s[i] == '1')
            res++;
    }
    cout << res << "\n";
    return 0;
}