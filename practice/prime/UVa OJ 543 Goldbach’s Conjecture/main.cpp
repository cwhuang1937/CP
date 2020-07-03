#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int mx = 1000005;
vector<int> V;
vector<bool> isP(mx, 1);

// O(n)
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    isP[1] = 0;
    for(int i = 2; i < mx; ++i) {
        if(isP[i])
            V.push_back(i);

        for(int p : V) {
            if(p*i >= mx)
                break;
            isP[p*i] = 0;
            if(i%p == 0)
                break;
        }
    }
    int n;
    while(cin >> n) {
        if(n == 0)
            break;
        bool f = 1;
        for(int p : V) {
            if(isP[n-p]) {
                cout << n << " = " << p << " + " << n-p << "\n";
                f = 0;
                break;
            }
        }
        if(f)
            cout << "Goldbach's conjecture is wrong.\n";
    }
    return 0;
}