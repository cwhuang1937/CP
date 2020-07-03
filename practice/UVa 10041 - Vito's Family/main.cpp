#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, r, mid;
    cin >> t; // read input case
    while(t--) {
        cin >> r; // read input relatives
        vector<int> V(r); // record all streets
        ll res = 0; // record the result 
        for(int i = 0; i < r; ++i)
            cin >> V[i]; // read all streets
        sort(V.begin(), V.end()); // sort in increasing order
        // find the median
        if(r%2 == 0)
            mid = (V[r/2-1] + V[r/2])/2;
        else
            mid = V[r/2];

        for(auto i : V) // calculate the result
            res += abs(i-mid);
        cout << res << "\n"; // output the result
    }
    return 0;
}