#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    char M[26];
    string s;
    string key[9] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    cin >> n;
    while(n--) {
        getline(cin, s);
        vector<stinrg> out;
        for(int i = 0; i < 26; ++i)
            M[i] = '-';
        while(getline(cin, s)) {
            out.push_back(s);
            stringstream ss(s);
            while(ss >> s) {
                for(int i = 0; i < 9; ++i) {
                    if(key[i].length() == s.length()) {
                        for(int j = 0; j < s.length(); ++j) {
                            if(M[s[j]] == '-')
                                M[s[j]] = key[i][j];
                        }
                    }
                }
            }
        }
    }
    return 0;
}