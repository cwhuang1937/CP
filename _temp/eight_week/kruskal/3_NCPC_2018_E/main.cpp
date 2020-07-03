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
	p[a]=b;
}
struct Edge{
	int u,v,w;
	bool operator<(Edge const& other){
		return w<other.w;
	}
};
vector<Edge> edges;
long long int result=1;
int n,m;
void solve(){
	int u,v,w;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		edges.push_back({u,v,w});
	}
	sort(edges.begin(),edges.end());
	for(int i=0;i<n;i++)
		p[i]=i;
	for(Edge e:edges){
		if( getP(e.u)!=getP(e.v) ){
			result=result*e.w;
			result%=65537;
			unite(e.u,e.v);
		}
	}
	cout<<result<<endl;
}
int main(){
    fio();
	while(cin>>n>>m &&n&&m){
		p.resize(n),result=1,edges.clear();
    	solve();
	}

}












