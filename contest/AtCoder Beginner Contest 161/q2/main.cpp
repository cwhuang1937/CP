#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    for(int i = 0; i < m; ++i) {
        if(a[i]*4*m < sum) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    
    return 0;
}