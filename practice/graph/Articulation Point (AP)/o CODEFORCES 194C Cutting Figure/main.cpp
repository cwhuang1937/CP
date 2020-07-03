#include<bits/stdc++.h>
#define INF 0xFF
using namespace std;
 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visit[51][51] = {false};
char mp[51][51];
int ans, n, m;
int dfs(int x, int y){
    if(visit[x][y] || mp[x][y] == '.')return 0;
    if(x >= 0 && x < n && y >= 0 && y < m){
        visit[x][y] = true;
        for(int i = 0; i < 4; i++)
            dfs(x+dx[i], y+dy[i]);
    }
    return 0;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int num = 0;
    cin>>n>>m; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mp[i][j];
            if(mp[i][j] == '#')
                num++;
        }
    }
    if(num < 3){
        cout<<"-1\n";
        return 0;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == '.')continue;
            memset(visit, false, sizeof(visit));
            
            int ans = 0;
            visit[i][j] = true;
            for(int x = 0; x < n; x++){
                for(int y = 0; y < m; y++){ 
                    if(!visit[x][y] && mp[x][y] == '#'){
                        dfs(x, y);
                        ans++;
                    }
                }
            }                       
            if(ans > 1){
                cout<<"1\n";
                return 0;
            }
        }
    }
    
    cout<<"2\n";
    return 0;
}