#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
const int MAXN = 2e5 + 5;
const int INF = 1e9;
int n,s;
struct Edge{
	int u,v,w;
};
vector<Edge> e;
vector<int> d;
vector<int> p;
int cnt;

void solve(){
	int u,v,m;
	while(cin>>u>>v &&u&&v ){
		e.push_back({u,v,1});	
	}
	m=e.size();
	for(;;){
		bool any = false;
		for(int j=0;j<m;j++)
			if( d[e[j].v] < d[e[j].u]+e[j].w ){
				d[e[j].v] = d[e[j].u]+e[j].w;
				p[e[j].v] = e[j].u;
				any=true;
			}
		if(!any) break;
	}
	int t=-1;
	for(int i=1;i<=n;i++) t=max(t,d[i]);
	for(int i=1;i<=n;i++) 
		if( d[i]==t ){
			t = i;
			break;
		}
	vector<int> path;
	for(int cur=t;cur!=-1;cur=p[cur])
		path.push_back(cur);
	reverse(path.begin(),path.end());
	cout<<"Case "<<++cnt<<": The longest path from "<<s<<" has length "<<path.size()-1<<", finishing at "<<path[path.size()-1]<<"."<<endl<<endl;
}
int main(){
    fio();
	while(cin>>n && n){
		cin>>s;
		e.clear(),d.resize(n+1),fill(d.begin(),d.end(),0),d[s]=INF;
		p.resize(n+1),fill(p.begin(),p.end(),-1);
		solve();

	}

}












