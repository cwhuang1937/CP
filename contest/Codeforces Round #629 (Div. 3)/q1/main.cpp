#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        int c = a % b;
        if(c == 0)
            cout << 0 << "\n";
        else {
            
            cout << b - c << "\n";
        }
    }
    return 0;
}