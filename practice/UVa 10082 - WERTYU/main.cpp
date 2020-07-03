#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s, s1, s2;
    // record all the possible character to a hash map
    s1 = "WERTYUIOP[]\\SDFGHJKL;,'XCVBNM,./1234567890-=";
    s2 = "QWERTYUIOP[]ASDFGHJKLM;ZXCVBNM,.`1234567890-";
    unordered_map<char, char> M;
    for(int i = 0; i < s1.length(); ++i) // build the hash map
        M[s1[i]] = s2[i];

    while(getline(cin, s)) { // read input
        for(int i = 0; i < s.length(); ++i)
            if(M.count(s[i])) // use map to convert to corresponding characters
                cout << M[s[i]];
            else // output the same with the input
                cout << s[i];
        cout << "\n";
    }
    return 0;
}