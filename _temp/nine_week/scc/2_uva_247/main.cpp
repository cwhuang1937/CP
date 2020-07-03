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
map<string,int> mymap;
vector<string> sm;
int ans_order;

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
	component.push_back(v);
	for(int i=0;i<gr[v].size();i++){
		if( !used[ gr[v][i] ] ) dfs2(gr[v][i]);
	}
}


void solve(){
	g.clear(),g.resize(n);
	gr.clear(),gr.resize(n);
	mymap.clear();
	sm.clear();

	string sa,sb;
	int a,b,num=0;
	for(int i=0;i<m;i++){
		cin>>sa>>sb;
		if( mymap.count(sa)==0 )  mymap[sa]=num++,sm.push_back(sa);
		if( mymap.count(sb)==0 )  mymap[sb]=num++,sm.push_back(sb);
		a = mymap[sa],b = mymap[sb];	
		g[a].push_back(b);
		gr[b].push_back(a);
	}
	
	order.clear();
	used.assign(n,false);
	for(int i=0;i<n;i++)
		if(!used[i])
			dfs1(i);
	used.assign(n,false);
	cout<<"Calling circles for data set "<<++ans_order<<":"<<endl;
	for(int i=0;i<n;i++){
		int v = order[n-1-i];
		if(!used[v]){
			dfs2(v);
			for(int i=0;i<component.size();i++){
				if(i==0) cout<<sm[ component[i] ];
				else cout<<", "<<sm[ component[i] ];
			}
			component.clear();
			cout<<endl;
		}
	}


	return;
}
int main(){
    fio();
	int temp_cnt=0;
	while(cin>>n>>m){
		if(n==0&&m==0) break;
		if(temp_cnt!=0) cout<<endl;
		solve();
		temp_cnt++;
	}
}












