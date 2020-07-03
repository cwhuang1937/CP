#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    // cout << "a: \n";
    // for(auto i : a)
    //     cout << i << " ";
    // cout << "\n";

    b = a;
    sort(b.begin(), b.end());
    unique(b.begin(), b.end());

    // cout << "b: \n";
    // for(auto i : b)
    //     cout << i << " ";
    // cout << "\n";

    for(auto &i : a)
        i = lower_bound(b.begin(), b.end(), i) - b.begin() + 1;

    for(auto i : a)
        cout << i << " ";
    cout << "\n";
    return 0;
}