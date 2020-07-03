#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    int arr[n];
    map<int, int> m;
    for(int  i = 0; i < n; ++i) {
        cin >> arr[i];
        for (int j = 0; j <= 5; ++j) {
            m[arr[i] + j]++;
        }
    }
    int maxn = 0;
    for(auto it = m.begin(); it != m.end(); ++it)
        maxn = max(maxn, it->second);

    cout << maxn << '\n';

    return 0;
}