#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int count = 0;
    cin >> n;
    map<string, int> M;
    string sn;
    while(n--) {
        int ope;
        cin >> ope;
        if(ope == 1) {
            string s;
            cin >> s;
            M[s] = count;
            count++;
        }
        else if(ope == 2) {
            if(!M.empty()) {
                int maxn = 0;
                string s;
                for(auto it = M.begin(); it != M.end(); ++it) {
                    if(it->second >= maxn) {
                        maxn = it->second;
                        s = it->first;
                    }
                }
                M.erase(s);
            }
        }
        else {
            string s;
            cin >> s;
            if(M.count(s)) {
                cout << "Y";
            }
            else {
                cout << "N";
            }
        }
    }
    cout << "\n";
    return 0;
}