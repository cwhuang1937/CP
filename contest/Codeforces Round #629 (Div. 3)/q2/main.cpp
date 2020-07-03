#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int count = 0;
        int start, end;
        for(int i = 1; i <= n-1; ++i) {
            if(count + i >= k) {
                start = i + 1;
                end = k - count;
                // cout << start << " " << end << "\n";
                break;
            }
            else
                count += i;
        }
        string s(n, 'a');
        for(int i = 1; i <= n; ++i) {
            if(i == start || i == end)
                s[n-i] = 'b';
        }
        cout << s << "\n";



    }
    return 0;
}