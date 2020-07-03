#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, K;
    string s;
    cin >> N >> K >> s;
    int cnt[K];
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < N; ++i)
        cnt[s[i]-'A']++;

    int res = INT_MAX;
    for(int i = 0; i < K; ++i)
        res = min(res, cnt[i]);

    cout << res*K << "\n";

    
    
   
    return 0;
}