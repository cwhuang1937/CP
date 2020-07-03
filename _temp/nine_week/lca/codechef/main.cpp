#include<bits/stdc++.h>
#define LL long long
using namespace std;

#define maxn 300111
#define logN 20


vector<int> adj[maxn];
int up[maxn][logN],depth[maxn],n;

void dfs(int v){
    for(int i=1;i<logN;i++)
        up[v][i] = up[ up[v][i-1] ][i-1];
    
    for(int u:adj[v]){
        if( !depth[u] ){ //not visit
            up[u][0] = v;
            depth[u] = depth[v]+1;
            dfs(u);
        }
    }
}

int lca(int u,int v){
    //depth u is large
    if( depth[u]<depth[v] ) swap(u,v);

    //往上找 直到找到ancestor (depth小於depth[v])
    for(int i=logN-1; i>=0;i--)
        if(depth[up[u][i]] >= depth[v]){ //if no this node->depth equals 0
            u = up[u][i];
        }
    if( u==v ) return v;
    
    for(int i=logN-1;i>=0;i--)
        if( up[u][i]!=up[v][i] ){
            u = up[u][i];
            v = up[v][i];
        }

    return up[u][0];
}

int dist(int u,int v){
    int x=lca(u,v);
    int res=depth[u]+depth[v]-2*depth[x];
    return res;
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[1] = 1;
    dfs(1);

    int q;
    cin>>q;
    
    pair<int,int> p[6];
    while(q--){
        int u,v,r;
        cin>>r>>u>>v;

        p[0].second = u;
        p[1].second = v;
        p[2].second = r;
        p[3].second = lca(r,u);
        p[4].second = lca(r,v);
        p[5].second = lca(u,v);

        for(int i=0;i<6;i++){
            int x = p[i].second;
            p[i].first = dist(x,r) + dist(x,u) + dist(x,v);
        }
        
        sort(p,p+6);

        cout<<p[0].second<<endl;
    }
}
