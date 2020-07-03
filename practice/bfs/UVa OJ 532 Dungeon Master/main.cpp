#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct point {
    int l, r, c, t;
};

const int dx[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int L, R, C;
    
    while(cin >> L >> R >> C) {
        if(L == 0)
            break;

        int dun[L][R][C];
        queue<point> Q;
        for(int i = 0; i < L; ++i) {
            for(int j = 0; j < R; ++j) {
                for(int k = 0; k < C; ++k) {
                    char c;
                    cin >> c;
                    if(c == '.')
                        dun[i][j][k] = INT_MAX;
                    else if(c == '#')
                        dun[i][j][k] = 0;
                    else if(c == 'S') {
                        dun[i][j][k] = 0;
                        Q.push({i, j, k, 0});
                    }
                    else
                        dun[i][j][k] = -1;
                }
            }
        }
        bool f = false;
        while(!Q.empty()) {
            point p = Q.front();
            Q.pop();

            for(int i = 0; i < 6; ++i) {
                int l = p.l + dz[i];
                int r = p.r + dy[i];
                int c = p.c + dx[i];
                int t = p.t + 1;
                if(l < 0 || r < 0 || c < 0 || l == L || r == R || c == C || (dun[l][r][c] != INT_MAX && dun[l][r][c] != -1))
                    continue;
                
                if(dun[l][r][c] == -1) {
                    f = true;
                    cout << "Escaped in " << t << " minute(s)." << "\n";
                    break;
                }
                dun[l][r][c] = t;
                Q.push({l, r, c, t});
                
            }
            if(f)
                break;
        }
        if(!f)
            cout << "Trapped!\n";
    }
    return 0;
}