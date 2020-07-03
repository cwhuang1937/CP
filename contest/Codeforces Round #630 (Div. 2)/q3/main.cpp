#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

string s[1000000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int t, n, k, cnt;
    string ss;
    cin >> t;
    while(t--) {
        cin >> n >> k >> ss;
        for(int i = 0; i < n/k; ++i)
            s[i] = ss.substr(k*i, k);

        cnt = 0;
        for(int j = 0; j < k/2; ++j) {
            map<int, int> M;
            for(int i = 0; i < n/k; ++i) {
                M[s[i][j]]++;
                M[s[i][k-1-j]]++;
            }
            int maxN = 0;
            for(auto it = M.begin(); it != M.end(); ++it) {
                if(it->second > maxN)
                    maxN = it->second;
            }
            cnt += 2*n/k - maxN;
        }
        
        if(k%2 == 1) {
            map<int, int> M;
            for(int i = 0; i < n/k; ++i)
                M[s[i][k/2]]++;

            int maxN = 0;
            for(auto it = M.begin(); it != M.end(); ++it) {
                if(it->second > maxN)
                    maxN = it->second;
            }
            cnt += n/k - maxN;
        }

        cout << cnt << "\n";
    }
    return 0;
}