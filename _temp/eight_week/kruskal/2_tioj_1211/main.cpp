#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
const int MAXN = 2e5 + 5;
long long int cost;
int n,m;
vector<int> p;

int getP(int a){
	return (a==p[a]? a:p[a]=getP(p[a]));
}
void unite(int a,int b){
	a = getP(a);
	b = getP(b);
	if( a==b ) return;
	p[a] = b;
}
struct Edge{
	int u,v,weight;
	bool operator<(Edge const& other){
		return weight<other.weight;
	}
};
vector<Edge> edges;
void solve(){
	int a,b,c;
	for(int i=1;i<=n;i++)
		p[i] = i;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		edges.push_back({a,b,c});		
	}
	sort(edges.begin(),edges.end());	
	for(Edge e:edges){
		if( getP(e.u)!=getP(e.v) ){
			cost+=e.weight;
			unite(e.u,e.v);
		}
	}
	for(int i=1;i<n;i++)
		if( getP(i)!=getP(i+1) ){
			cout<<"-1"<<endl;
			return;
		}
	cout<<cost<<endl;
	
}
int main(){
    fio();
	while(cin>>n>>m &&n&&m){
		cost=0,edges.clear(),p.resize(n+1);
		solve();
	}

}












