#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int const mxN = 101;
int cnt[mxN] = {0};
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, num;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> num;
        cnt[num]++;
    }
    for(int i = mxN-1; i >= 1; --i) {
        while(cnt[i] != 0) {
            cout << i << " ";
            cnt[i]--;
        }
    }
    cout << "\n";
    return 0;
}