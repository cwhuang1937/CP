#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n) {
        if(n%10 == 7) {
            cout << "Yes\n";
            return 0;
        }
        n=n/10;
    }
    cout << "No\n";
    return 0;
}