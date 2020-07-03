#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

char a[101][101];

int m, n, cnt;
void dfs(int x, int y) {
    if(a[x][y] == '*')
        return;

    a[x][y] = '*';
    for(int i = -1; i <= 1; ++i)
        for(int j = -1; j <= 1; ++j)
            if(x+i >= 0 && x+i < m && y+j >= 0 && y+j < n)
                dfs(x+i, y+j);

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    while(cin >> m >> n){
        if(m == 0)
            break;

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                cin >> a[i][j];

        cnt = 0;

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(a[i][j] == '@') {
                    dfs(i , j);
                    cnt++;
                }

        cout << cnt << "\n";
    }

    return 0;
}