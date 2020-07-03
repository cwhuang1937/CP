#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, num;
    cin >> n >> k;
    
    deque<pair<int ,int>> dq;

    for(int i = 0; i < k-1; ++i) {
        cin >> num;
        while(!dq.empty() && dq.back().second < num)
            dq.pop_back();
        dq.push_back(make_pair(i, num));
    }

    for(int i = k-1; i < n; ++i) {
        cin >> num;
        while(!dq.empty() && dq.back().second < num)
            dq.pop_back();
        dq.push_back(make_pair(i, num));

        while(!dq.empty() && dq.front().first <= i - k)
            dq.pop_front();
        cout << dq.front().second << " ";       
    }
    cout << "\n";
    return 0;
}