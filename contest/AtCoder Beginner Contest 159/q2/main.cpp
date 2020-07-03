#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();

    if(n % 2 == 0) {
        cout << "No\n";
        return 0;     
    }
    else {
        for (int i = 1; i <= n / 2; ++i) {
            if(s[n/2 + i] != s[n/2 - i]) {
                cout << "No\n";
                return 0;
            }
        }
        for (int i = 1; i <= (n-1) / 4; ++i) {
            if(s[0+i] != s[(n-1)/2-1-i]) {
                cout << "No\n";
                return 0;
            }
            if(s[n-1-i] != s[(n+3)/2-1+i]) {
                cout << "No\n";
                return 0;
            }
        }
        cout << "Yes\n";
    }
    return 0;
}