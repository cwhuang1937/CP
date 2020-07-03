#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

#define INF INT_MAX 
struct point {
    int r, c, t;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int t, m, n;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        int ma[m][n];
        queue<tuple<int, int, int>> q1, q2;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                char c;
                cin >> c;
                if(c == '#') {
                    ma[i][j] = INF;
                }
                else if(c == '.') {
                    ma[i][j] = 0;
                }
                else if(c == 'J') {
                    ma[i][j] = INF;
                    q1.push({i, j, 0});
                }
                else {
                    ma[i][j] = 0;
                    q2.push({i, j, 0});
                }
            }
        }
        while(q2)
    }
    return 0;
}