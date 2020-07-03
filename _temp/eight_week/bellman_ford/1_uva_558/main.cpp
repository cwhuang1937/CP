#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
const int MAXN = 2e5 + 5;
const int INF = 1e9;
int n,m,t;

struct Edge{
	int u,v,w;
};
vector<Edge> e;
vector<int> d;
void solve(){
	int u,v,w;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	int x;
	for(int i=0;i<n;i++){
		x=-1;
		for(int j=0;j<m;j++){
			if( d[e[j].v] > d[e[j].u]+e[j].w ){
				d[e[j].v] = max(-INF,d[e[j].u]+e[j].w);
				x = e[j].v;
			}
		}
	}
	if( x==-1 )
		cout<<"not possible"<<endl;
	else cout<<"possible"<<endl;
	

	return;
}
int main(){
    fio();
	cin>>t;
	while(t--){
		cin>>n>>m;
		e.clear();
		d.resize(n);
		fill(d.begin(),d.end(),INF);
		d[0]=0;
		solve();
	}
}












