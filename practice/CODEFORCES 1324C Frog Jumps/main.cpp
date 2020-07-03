#include<bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int sum = 0;
        int ans = 0;
        // cout << s.length() << '\n';
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == 'L') {
                sum++;
                ans = max(ans, sum);
            }        
            else {            
                sum = 0;
            }
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}