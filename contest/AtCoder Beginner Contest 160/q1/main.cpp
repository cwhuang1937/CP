#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s;
    cin >> s;
    if(s[2] == s[3] && s[4] == s[5])
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}