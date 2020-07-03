#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string s, ss = "";
    cin >> s;
    // string preprocessing
    if(s.length() == 0)
        ss = "^$";
    else {
        ss += "^";
        for (int i = 0; i < s.length(); ++i) {
            ss = ss + "#" + s[i];
        }
        ss += "#$";
    }
    // Manacher Algorithm
    int len = ss.length();
    int p[len] = {0};
    int c = 0, r = 0;
    for (int i = 1; i < len - 1 ; ++i) { // range !!!!!
        int i_left = 2 * c - i; // i_left + i_right = 2 * center
        if(r > i) // i is in the radius range
            p[i] = min(r - i, p[i_left]);
        else
            p[i] = 0;
        while(ss[i + 1 + p[i]] == ss[i - 1 - p[i]]) // extend the range
            p[i]++;

        if(i + p[i] > r) {
            c = i;
            r = c + p[c];
        }
        // cout << "i = " << i << '\n';
        // for (int i = 0; i < len; ++i) {
        //     cout << ss[i] << " ";
        // }
        // cout << '\n';
        // for (int i = 0; i < len; ++i) {
        //     cout << p[i] << " ";
        // }
        // cout << "\n\n";
    }
    int maxlen = 0;
    int center = 0;
    for (int i = 1; i < len - 1; ++i) {
        if(p[i] > maxlen) {
            maxlen = p[i];
            center = i;
        }
    }
    // for (int i = 1; i < len - 1; ++i) {
    //     cout << p[i] << " ";
    // }
    // cout << '\n';
   
    int start = (center - maxlen) / 2;
    // cout << center << " " << maxlen << '\n';
    // cout << start;
    cout << s.substr(start, maxlen) << "\n";

    return 0;
}