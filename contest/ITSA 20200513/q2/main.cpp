#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[100] = {0}, b[6];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        cin >> a[i];
    }
    sort(a, a+n, greater<int>());
    int res = 0;
    int idx = 6;
    vector<int> V;
    for(int i = 0; i < 6; ++i)
        V.push_back(a[i]);

    while(1) {   
        if(V.size() != 6)
            break;
        res += V[5];
        for(int i = 0; i < 6; ++i) {
            V[i] -= V[5]; 
        }
        

        while(V.back() == 0 && V.size() == 6) {
            V.pop_back();
            if(idx < n)
                V.push_back(a[idx++]);
            sort(V.begin(), V.end(), greater<int>());

        }
    }
    
    cout << res*5 << "\n";
    



    return 0;
}