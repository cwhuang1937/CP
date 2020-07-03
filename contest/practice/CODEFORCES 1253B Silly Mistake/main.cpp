#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int day = 0;
    int count = 0;

    vector<int> V;
    set<int> S, R;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if(R.count(num)) {
            cout << -1 << '\n';
            return 0;
        }
        if(num > 0) {
            S.insert(num);
            R.insert(num);
        }
        else {
            if(S.count(-num)) {
                S.erase(-num);
                count += 2;
                if(S.empty()) {
                    V.push_back(count);
                    count = 0;                  
                    day += 1;
                    R.clear();
                }
            }
            else {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    if(S.empty()) {
        cout << day << '\n';
        for (int i = 0; i < day; ++i) {
            cout << V[i] << " ";
        }
    }
    else {
        cout << -1 << '\n';
    }
    return 0;
}