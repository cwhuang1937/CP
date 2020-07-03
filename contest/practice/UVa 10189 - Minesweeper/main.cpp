#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

char grid[110][110];
int field[110][110] = {0};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n;
    int num = 1;
    bool flag = false;
    while(1) {
        cin >> m >> n;
        if(m == 0)
            break;
        if (flag)
            cout << "\n";
        flag = true;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> grid[i][j];
                field[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if(grid[i][j] == '*') {
                    for (int k = -1; k <= 1; ++k) {
                        for (int t = -1; t <= 1; ++t) {
                            field[i + k][j + t]++;
                        }
                    }
                }
            }
        }
        cout << "Field #" << num << ":\n";
        num++;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if(grid[i][j] == '*')
                    cout << '*';
                else
                    cout << field[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}