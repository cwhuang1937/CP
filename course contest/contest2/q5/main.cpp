#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
int n,m,k;
int bfs()
{
    queue<int> Q;
    bool vis[n]={false};
    Q.push(root); //root 代表走訪此圖的起點
    vis[root] = true;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto& v: E[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        Q.push(v);
    }
}
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin>>n>>m>>k;
    int special[k];
    int grass[n][n]={0};
    int previous[n]={-1};
    for (int i=0;i<k;++i)
    {
        cin>>special[i];
    }
    for(int i=0;i<m;++j)
    {
        int r,c;
        cin>>r>>c;
        grass[i][j]=1;
        grass[j][i]=1;
    }

    for (int i=0;i<k-1;++i)
    {
        for (int j=i+1;j<k;++j)
        {
            int u=special[i];
            int v=special[j];
            grass[u][v]=1;
            grass[v][u]=1;

        }
    }
    return 0;
}