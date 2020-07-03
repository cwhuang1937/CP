#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    int dp1[n], dp2[n];
    memset(dp1, 0, sizeof dp1);
    memset(dp2, 0, sizeof dp2);
    if(s1[0] == 'A')
        dp1[0] = 1;
    if(s2[0] == 'A')
        dp2[0] = 1;

    for(int i = 1; i < n; ++i)
        if(s1[i] == 'A')
            dp1[i] = dp1[i-1] + 1;
        else
            dp1[i] = dp1[i-1];
    for(int i = 1; i < n; ++i)
        if(s2[i] == 'A')
            dp2[i] = dp2[i-1] + 1;
        else
            dp2[i] = dp2[i-1];

    ll cnt1 = 0;
    ll cnt2 = 0;
    for(int i = 0; i < n; ++i)
        if(s1[i] == 'K')
            cnt1 += dp1[i]*(dp1[n-1]-dp1[i]); 
    for(int i = 0; i < n; ++i)
        if(s2[i] == 'K')
            cnt2 += dp2[i]*(dp2[n-1]-dp2[i]); 

    if(cnt1 == cnt2)
        cout << "WINWIN\n";
    else if(cnt1 > cnt2)
        cout << "LanA WIN\n";
    else
        cout << "LanE WIN\n";

    return 0;
}