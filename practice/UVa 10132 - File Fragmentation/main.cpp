#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    string s;
    cin >> t;
    getline(cin, s);
    getline(cin, s);
    for(int k = 0; k < t; ++k) {
        if(k != 0)
            cout << "\n";
        vector<string> V;
        unordered_map<string, int> M;
        while(getline(cin, s)) {
            if(s == "\r" || s == "")
                break;
            if(s[s.length()-1] == '\r')
                s = s.substr(0, s.length()-1);
            V.push_back(s);
        }

        for(int i = 0; i < V.size(); ++i) {
            for(int j = i+1; j < V.size(); ++j) {
                M[V[i]+V[j]]++;
                M[V[j]+V[i]]++;
            }
        }
        for(auto i : M) {
            if(i.second >= V.size()/2) {
                cout << i.first << "\n";
                break;
            }
        }
    }

    return 0;
}