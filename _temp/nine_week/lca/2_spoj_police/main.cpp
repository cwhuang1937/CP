#include<bits/stdc++.h>
#define LL long long
using namespace std;

#define maxn 300111
#define logN 20


vector<int> adj[maxn];
int up[maxn][logN],depth[maxn],n;

void dfs(int v){
    ///建立v往上4個的祖先 可以由v往上兩個祖先後再往該點上兩個祖先
    //16=8+8
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

    //往上找 直到兩個深度一樣 
    for(int i=logN-1; i>=0;i--)
        if(depth[up[u][i]] >= depth[v]){ //如果跳完之後 深度還是比較大才可以跳 確保最後可以跳到一樣
            u = up[u][i];
        }
    if( u==v ) return v;
    
    for(int i=logN-1;i>=0;i--)
        if( up[u][i]!=up[v][i] ){ //祖先是不相同的 代表小於LCA(u,v) 這樣才可以跳
            //3拆成 2 1
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
        int u,v;
        int r=1;
        cin>>u>>v;
        int lca_n = lca(u,v);  
        int thief = depth[u]-depth[lca_n];
        int your  = depth[v]-depth[lca_n];
        if(your<=thief) {
            cout<<"YES"<<" "<<lca(u,v)<<endl;
        }
        else 
            cout<<"NO"<<endl;
    }
}
