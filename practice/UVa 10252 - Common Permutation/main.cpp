#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s1, s2;
    while(getline(cin, s1)) { // read string1
        getline(cin, s2); // read string2
        int r1[26], r2[26]; // record the common characters
        memset(r1, 0, sizeof r1); // initialize to 0
        memset(r2, 0, sizeof r2);
        for(int i = 0; i < s1.length(); ++i)
            r1[s1[i]-'a']++;
        for(int i = 0; i < s2.length(); ++i)
            r2[s2[i]-'a']++;
        // concatenate the common charaters to a string
        string res = "";
        for(int i = 0; i < 26; ++i) {
            int cnt = min(r1[i], r2[i]);    
            while(cnt--)
                res += 'a'+i;
        }
        cout << res << "\n"; // output the result
    }
    return 0;
}