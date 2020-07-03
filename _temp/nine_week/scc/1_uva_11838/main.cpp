#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
// const int MAXN = 30+5;
const int INF = 1e9;
typedef pair<int,int> P;

int n,m;
vector< vector<int> > g,gr;
vector<bool> used;
vector<int> order,component;

void dfs1(int v){
	used[v] = true;
	for(int i=0;i<g[v].size();i++){
		if( !used[ g[v][i] ] ) dfs1(g[v][i]);		
	}
	order.push_back(v);
	
	return;
}
void dfs2(int v){
	used[v] = true;
	for(int i=0;i<gr[v].size();i++){
		if( !used[ gr[v][i] ] ) dfs2(gr[v][i]);
	}
}


bool solve(){
	g.clear(),g.resize(n);
	gr.clear(),gr.resize(n);

	int a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		a--,b--;
		if( c==2 ) {
			g[b].push_back(a);
			gr[a].push_back(b);
		}
		g[a].push_back(b);
		gr[b].push_back(a);
	}
	
	order.clear();
	used.assign(n,false);
	for(int i=0;i<n;i++)
		if(!used[i])
			dfs1(i);
	used.assign(n,false);
	int cnt=0;
	for(int i=0;i<n;i++){
		int v = order[n-1-i];
		if(!used[v]){
			dfs2(v);
			component.clear();
			cnt++;
		}
	}
	if(cnt > 1) return false;
	else return true;





}
int main(){
    fio();
	while(cin>>n>>m){
		if(n==0&&m==0) break;
    	if( solve() ) cout<<1<<endl;
		else cout<<0<<endl;
	}
}












