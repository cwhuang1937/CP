#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> V[n+1];
        bool prin[100010] = {false};

        for(ll i = 1; i <= n; ++i) {
            ll num;
            cin >> num;
            for(ll j = 0; j < num; ++j) {
                ll ele;
                cin >> ele;
                V[i].push_back(ele);
            }            
        }
        ll rec;
        for(ll i = 1; i <= n; ++i) {
            bool f = false;
            for(ll j = 0; j < V[i].size(); ++j) {
                if(!prin[V[i][j]]) {
                    prin[V[i][j]] = true;
                    f = true;
                    break;
                }
            }
            if(!f) {
                rec = i;
            }     
        }
        bool f2 = false;
        // for(ll i = 1; i <= n; ++i) {
        //     cout << prin[i] << "\n";
        // }
        for(ll i = 1; i <= n; ++i) {
            if(!prin[i]) {
                cout << "IMPROVE\n" << rec << " " << i << "\n";
                f2 = true;
                break;
            }
        }
        if(!f2)
            cout << "OPTIMAL\n";
    }
    return 0;
}