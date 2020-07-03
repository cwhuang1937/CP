#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

#define INF INT_MAX 
struct point {
    int r, c, t;
};
const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int t, m, n;
    
    cin >> t;
    while(t--) {
        cin >> m >> n;
        int ma[m][n];
        bool vis[m][n] = {false};
        queue<point> q1, q2;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                char c;
                cin >> c;
                if(c == '#') {
                    ma[i][j] = 0;
                }
                else if(c == '.') {
                    ma[i][j] = INF;
                }
                else if(c == 'J') {
                    ma[i][j] = INF;
                    q1.push({i, j, 0});
                    vis[i][j] = true;
                }
                else {
                    ma[i][j] = 0;
                    q2.push({i, j, 0});
                }
            }
        }
        while(!q2.empty()) {
            point p = q2.front();
            q2.pop();
            for(int i = 0; i < 4; ++i) {
                int r = p.r + dr[i];
                int c = p.c + dc[i];
                if(r < 0 || c < 0 || r == m || c == n || ma[r][c] != INF)
                    continue;
                ma[r][c] = p.t + 1;
                q2.push({r, c, p.t+1});
            }
        }
        bool f = false;
        int steps;
        while(!q1.empty()) {
            point p = q1.front();
            q1.pop();
            if(p.r == 0 || p.c == 0 || p.r == m-1 || p.c == n-1) {
                f = true;
                steps = p.t + 1;
                break;
            }
            for(int i = 0; i < 4; ++i) {
                int r = p.r + dr[i];
                int c = p.c + dc[i];
                if(p.t + 1 >= ma[r][c] || vis[r][c])
                    continue;
                vis[r][c] = true;
                q1.push({r, c, p.t+1});
            }
        }
        if(f)
            cout << steps << "\n";
        else
            cout << "IMPOSSIBLE\n";

    }
    return 0;
}