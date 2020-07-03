#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int mxN = 1010;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, w;
    while(cin >> n >> w) {
        if(n == 0)
            break;
        vector<int> V(n);
        for(int i = 0; i < n; ++i)
            cin >> V[i];

        int l = *max_element(V.begin(), V.end());
        int r = mxN*mxN;
        while(l != r) {
            int m = (l+r)/2;
            int cost = 0;
            int cnt = 0;

            bool f = true;
            for(int j = 0; j < n; ++j) {
                cost += V[j];
                if(cost > m) {
                    cost = V[j];
                    cnt++;
                }
                if(cnt > w) {
                    f = false;
                    break;
                }
            }
            if(f)
                r = m;
            else
                l = m+1;

        }
        cout << l << "\n";
    }

    return 0;
}