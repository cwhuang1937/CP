#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define PB push_back
typedef long long lld;
typedef pair<lld,lld> pll;

#define N 1000
#define logN 15
#define INF 2147483647777

struct Edge{
	int s,e;
	lld v;
};

int g[N+5];
vector<Edge> Tree;
vector<pll> MST[N+5];
pll ff[N+5][logN+5];
int timer=0,time_in[N+5],time_out[N+5];

int Find(int a) {
    if(a == g[a])
        return a;
    return g[a] = Find(g[a]);
}
void Union(int a, int b) {
    g[Find(a)] = Find(b);
}

void dfs(lld w,lld f,lld v){
	time_in[w]=++timer;
	ff[w][0]={f,v};
	for(auto i:MST[w])
		if(i.first!=f) dfs(i.first,w,i.second);
	time_out[w]=++timer;
}
bool anc(int x,int y){
	return time_in[x]<=time_in[y]&&time_out[y]<=time_out[x];
}
int lca(int x,int y){
	if(anc(y,x))return y;
	for(int j=logN;j>=0;j--)
		if(!anc(ff[y][j].first, x)) y=ff[y][j].first;
	return ff[y][0].first;
}

lld walk(int x,int y){
	if(x==y)return 0;
	if(anc(y,x)) swap(x,y);
	lld rr=0;
	for(int i=logN;i>=0;i--){
		if(!anc(ff[y][i].first,x)){
			rr=max(rr, ff[y][i].second);
			y=ff[y][i].first;
		}
	}
	rr=max(rr, ff[y][0].second);
	return rr;
}
int main(){
	cin.tie(0);ios_base::sync_with_stdio();
	int n,m;
	cin >> n >> m;
	for(int i=0;i<N+5;i++) g[i]=i;
	for(int i=0;i<N+5;i++)for(int j=0;j<logN+5;j++)ff[i][j]={i,0};
	for(int i=0;i<m;i++){
		int a,b;lld c;
		cin>>a>>b>>c;
		Tree.PB({a,b,c});
	}
	sort(Tree.begin(),Tree.end(),[](const Edge& a,const Edge& b){return a.v<b.v;});
	queue<Edge> noMST;
	lld sumMST=0,countMST=0;
	for(auto i:Tree){
		if(Find(i.s)!=Find(i.e)){
			sumMST+=i.v;
			countMST++;
			Union(i.s,i.e);
			MST[i.s].PB({i.e,i.v});
			MST[i.e].PB({i.s,i.v});
		}else noMST.push(i);
	}
	if(countMST!=n-1)cout<<"-1 -1"<<endl;
	else if(noMST.empty()) cout<<sumMST<<" -1"<<endl;
	else{
		dfs(1,1,0);
		for(int j=1;j<=logN;j++){
			for(int i=1;i<=n;i++){
				ff[i][j].first = ff[ ff[i][j-1].first ][j-1].first;
				ff[i][j].second = max(ff[ff[i][j-1].first][j-1].second, ff[i][j-1].second);
			}
		}
		lld smst=INF;
		while(!noMST.empty()){
			auto tp=noMST.front();noMST.pop();
			int LCA = lca(tp.s,tp.e);
			lld tt = walk(tp.s,LCA);
			tt = max(tt, walk(tp.e,LCA));
			smst=min(smst, sumMST-tt+tp.v);
		}
		cout << smst<<endl;
	}
	return 0;
}

