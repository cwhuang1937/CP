#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll cnt = 0;
int board[8]; // record the chess's column index in this row

bool check(int r, int c) { // for backtracking
    for(int rr = 0; rr < r; ++rr) {
        int cc = board[rr];
        if(c == cc || c-cc == r-rr || c-cc == -(r-rr))
            return false;
    }
    return true;
}
void dfs(int r) {
    if(r == 8) {
        cnt++;
        return;
    }
    for(int c = 0; c < 8; ++c) {
        if(check(r, c)) {
            board[r] = c;
            dfs(r + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    dfs(0);
    cout << cnt << "\n";
    return 0;
}