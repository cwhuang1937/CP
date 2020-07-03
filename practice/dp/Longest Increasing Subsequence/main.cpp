#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> V;
    int dp[n], idx[n];
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        V.push_back(num);
    }
    for(int i = 0; i < n; ++i) {
        dp[i] = 1;
        idx[i] = i;
        for(int j = 0; j < i; ++j) {
            if(V[i] > V[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                idx[i] = j;
            }
        }
    }
    int maxn = 0;
    int index;
    vector<int> ans;
    for(int i = 0; i < n; ++i) {
        if(dp[i] >= maxn) {
            maxn = dp[i];
            index = i;
        }
    }
    for(int i = 0; i < maxn; ++i) {
        ans.push_back(index);
        index = idx[index];
    }
    for(int i = 0; i < maxn; ++i) {
        cout << V[ans.back()] << " ";
        ans.pop_back();
    }
    cout << "\n";
    
    return 0;
        
}