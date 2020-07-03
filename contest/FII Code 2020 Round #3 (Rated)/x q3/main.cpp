#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    int ins[101];
    string em;
    cin >> n >> m >> q;
    getline(cin, em);
    char map[n][m];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> map[i][j];

    string inst;
    cin >> inst;
    int len = inst.length();
    while(q--) {
        int x, y, z;
        cin >> x >> y >> z;

        int row = x - 1;
        int row_o = row;
        int col = y - 1;
        int col_o = col;
        bool flag = false;
        for(int i = 0; i < z/len; ++i) {
            for(int j = 0; j < len; ++j) {
                if(i != 0 && j == z%len) {
                    
                    if(row == row_o && col == col_o) {
                        flag = true;
                        break;
                    }
                    else {
                        row_o = row;
                        col_o = col;
                    }
                }
                if(inst[j] == 'U' && row != 0 && map[row-1][col] != '#')
                    row -= 1;
                else if(inst[j] == 'D' && row != n-1 && map[row+1][col] != '#')
                    row += 1;
                else if(inst[j] == 'L' && col != 0 && map[row][col-1] != '#')
                    col -= 1;
                else if(inst[j] == 'R' && col != m-1 && map[row][col+1] != '#')
                    col += 1;
            }
            if(flag)
                break;
        }
        if(!flag){
            for(int j = 0; j < z%len; ++j) {
                if(inst[j] == 'U' && row != 0 && map[row-1][col] != '#')
                    row -= 1;
                else if(inst[j] == 'D' && row != n-1 && map[row+1][col] != '#')
                    row += 1;
                else if(inst[j] == 'L' && col != 0 && map[row][col-1] != '#')
                    col -= 1;
                else if(inst[j] == 'R' && col != m-1 && map[row][col+1] != '#')
                    col += 1;
            }
        } 
        cout << row + 1 << " " << col + 1 << '\n';
    }

    return 0;
}