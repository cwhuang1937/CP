#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n, x, num;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        bool a[400] = {false};
        for(int i = 0; i < n; ++i) {
            cin >> num;
            a[num] = true;
        }
        
        for(int i = 1; i < 400; ++i) {
            if(x == 0)
                break;
            if(!a[i]) {
                x--;
                a[i] = true;
            }
        }
        int ans;
        for(int i = 1; i < 400; ++i) {
            if(!a[i]) {
                ans = i-1;
                break;
            }
        }
        cout << ans << "\n";

    }
    return 0;
}