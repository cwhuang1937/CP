#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int MAX = 101;
int a[MAX] = {0};
int dp[MAX] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    bool f = false;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(a[i] == 1)
            a[i] = -1;
        else {
            a[i] = 1;
            f = true;
        }
    }
    if(!f) {
        cout << n-1 << "\n";
        return 0;
    }



    dp[1] = a[1];
    for(int i = 2; i <= n; ++i) 
        dp[i] = max(dp[i-1] + a[i], a[i]);

    int start, end, maxn = 0;
    for(int i = 1; i <= n; ++i) {
        if(dp[i] >= maxn) {
            maxn = dp[i];
            end = i;
        }
    }
    for(int i = end; maxn > 0; --i) {
        maxn -= a[i];
        start = i;
    }
    for(int i = start; i <= end; ++i) {
        if(a[i] == -1)
            a[i] = 1;
        else
            a[i] = -1;
    }
    int count = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == -1)
            count++;
    }
    cout << count << "\n"; 

    return 0;
}