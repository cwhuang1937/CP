#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 50;
int p[MAXN * 2];
char ss[MAXN * 2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int len = s.length();
        int L = 0;
        int R = len - 1;

        while(s[L] == s [R] && R > L) {
            L++;
            R--;
        }
        if(L >= R) {
            cout << s << "\n";
            continue;
        }
        for (int i = 0; i < L; ++i) {
            cout << s[i];
        }
        // string preprocessing
        int k = 0;
        ss[k++] = '@';
        for (int i = L; i <= R; ++i) {
            ss[k++] = '#';
            ss[k++] = s[i];
        }
        ss[k++] = '#';
        ss[k++] = '$';
        int len_m = k;
        // Manacher's Algorithm
        int r = 0;
        int c = 0;

        int maxlen = 0;
        int pos = 0;
        for (int i = 1; i < len_m - 1; ++i) {
            if(r > i)
                p[i] = min(r - i, p[2 * c - i]);
            else
                p[i] = 0;

            while(ss[i + 1 + p[i]] == ss[i - 1 - p[i]])
                p[i]++;

            if(i + p[i] > r) {
                r = i + p[i];
                c = i;
            }
            if(p[i] > maxlen && p[i] == i - 1) {
                pos = 1;
                maxlen = p[i];
            }
            if(p[i] > maxlen && i + p[i] == len_m - 2) {
                pos = 2;
                maxlen = p[i];
            }
        }
        if(pos == 1) {
            for (int i = 0; i < maxlen; ++i)
                cout << s[L + i];
        }
        else {
            for (int i = 0; i < maxlen; ++i)
                cout << s[R - i];
        }
        for (int i = R + 1; i < len; ++i)
            cout << s[i];
        cout << "\n";
    }
    return 0;
}