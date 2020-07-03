#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int mxN = 10;
int cnt[mxN] = {0};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n; 
    int num, ans[n];
    for(int i = 0; i < n; ++i) {
        cin >> num;
        cnt[num]++;
    }
    int idx = 0;
    for(int num = 0; num < mxN; ++num) {
        while(cnt[num]--) {
            ans[idx++] = num;
        }
    }

    for(int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}