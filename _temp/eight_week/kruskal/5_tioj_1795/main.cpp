#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
const int MAXN = 2e5 + 5;
vector<int> p;
int getP(int a){
	return (a==p[a]? a:p[a]=getP(p[a]));
}
void unite(int a,int b){
	a=getP(a),b=getP(b);
	if(a==b) return;
	p[a] = b;
}
struct Edge{
	int u,v,w;
	bool operator<(Edge const& other){
		return w<other.w;
	}
};
vector<Edge> edges;
int n,m,k;
long long int kruskal(){
	long long int ans=0;
	for(Edge e:edges){
		if( getP(e.u)!=getP(e.v) ){
			unite(e.u,e.v);
			ans+=e.w;
		}
	}
	return ans;
}
void ini(){
	for(int i=1;i<=n;i++) p[i]=i;
}
void solve(){
	int u,v,w;
	long long int mi,Mi;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		edges.push_back({u,v,w});
	}
	sort(edges.begin(),edges.end());	
	ini();
	mi = kruskal();
	
	sort(edges.rbegin(),edges.rend());
	ini();
	Mi = kruskal();

	if( k>=mi && k<=Mi)  cout<<"TAK"<<endl;
	else cout<<"NIE"<<endl;
	return;
}
int main(){
    fio();
	cin>>n>>m>>k;
	p.resize(n+1);
    solve();

}












