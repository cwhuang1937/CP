#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n;
    string in, s;
    cin >> t;
    while(t--) {
        cin >> n >> in;
        stringstream ss;
        ss << in;
        ss >> s;
        string ans1(n, '1');
        string ans2(n, '1');

        bool f = false;
        for(int i = 1; i < n; ++i) {
            if(f) {
                ans1[i] = '0';
                ans2[i] = s[i];
            }
            else {
                if(s[i] == '1') {
                    ans1[i] = '1';
                    ans2[i] = '0';
                    f = true;
                }
                else if(s[i] == '0'){
                    ans1[i] = '0';
                    ans2[i] = '0';
                }

            }
            
        }
        cout << ans1 << "\n" << ans2 << "\n";
    }
    return 0;
}