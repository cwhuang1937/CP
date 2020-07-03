#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, m, n, q;
    char c;
    string s;
    cin >> t;
    for(int w = 0; w < t; ++w) {
        if(w != 0)
            cout << "\n";
        cin >> m >> n;
        char M[m][n];
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> c;
                M[i][j] = tolower(c);
            }
        }
        cin >> q;
        getline(cin, s);
        while(q--) {
            bool f = 0;
            getline(cin, s);
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if((char)tolower(s[0]) != M[i][j])
                        continue;
                    for(int l = 0; l < 8; ++l) {
                        for(int k = 1; k < s.length(); ++k) { // windows needs to -1
                            if(i+dy[l]*k >= 0 && j+dx[l]*k >= 0 && i+dy[l]*k < m && j+dx[l]*k < n && (char)tolower(s[k]) == M[i+dy[l]*k][j+dx[l]*k]) {
                                f = 1;
                            }
                            else {
                                f = 0;
                                break;
                            }
                        }
                        if(f)
                            break;
                    }
                    if(f) {
                        cout << i+1 << " " << j+1 << "\n";
                        break;
                    }
                }
                if(f) {
                    break;
                }
            }
        }
        
    }
    return 0;
}