#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> V(n);

    for(int i = 0; i < n; ++i)
        cin >> V[i];

    for(int i = 1; i < n; ++i)
        for(int j = i-1; j >= 0; --j)
            if(V[j] >= V[j+1])
                swap(V[j], V[j+1]);

    for(int i = 0; i < n; ++i)
        cout << V[i] << " ";
    cout << "\n";

    return 0;
}