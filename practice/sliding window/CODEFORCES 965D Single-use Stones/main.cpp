#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

deque<int> q;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int w, j, x;
    cin >> w >> j;
    for(int i = 1; i <= j; ++i) {
        cin >> x;
        q.push_back(x);
    }
    for(int i = j+1; i <= w-1; ++i) {
        cin >> x;
        if(x > 0) {
            ll count = 0;
            for(auto it = q.begin(); it != q.end(); ++it) {
                if(*it + count <= x) {
                    count += *it;
                    *it = 0;
                }
                else {
                    *it -= (x - count); 
                    count = x;                   
                }
                if(x == count)
                    break;
            }
            q.push_back(count); 
        }
        else {
            q.push_back(0);
        }
        q.pop_front();
    }
    ll total = 0;
    for(auto it = q.begin(); it != q.end(); ++it) {
        // cout << *it << "\n";
        total += *it;
    }
    // cout << q.size() << "\n";
    cout << total << "\n";


    return 0;
}