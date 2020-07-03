#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
struct point {
    int r, c, t;
};
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int t, N, M, K;
    queue<point> Q;
    cin >> t;
    while(t--) {
        cin >> N >> M >> K;
        char m[N][M];
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                cin >> m[i][j];
                if(m[i][j] == '@') {
                    Q.push({i, j, 0});
                    m[i][j] = '.';
                }
            }
        }
        unordered_map<char, bool> um;
        bool f = false;
        while(!Q.empty()) {
            point p = Q.front();
            Q.pop();
            for(int i = 0; i < 4; ++i) {
                int r = p.r + dy[i];
                int c = p.c + dx[i];
                int t = p.t + 1; 
                
                if(r < 0 || c < 0 || r == N || r == M || r == '#')
                    continue;

                if(m[r][c] == '*') {
                    cout << t << "\n";
                    f = true;
                    break;
                }
                if(m[r][c] >= 'a' && m[r][c] <= 'z')
                    um['A' + m[r][c]-'a'] = true;
                else if(m[r][c] >= 'A' && m[r][c] <= 'Z' && !um[m[r][c]])
                        continue;
                else
                    m[r][c] = '.';
                Q.push({r, c, t});

            }
            if(f)
                break;
        }
        if(!f)
            cout << -1 << "\n";
    }
    return 0;
}