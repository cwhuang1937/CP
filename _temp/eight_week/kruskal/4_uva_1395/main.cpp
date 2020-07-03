#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
const int MAXN = 2e5 + 5;
struct Edge{
	int u,v,w;
	bool operator<(Edge const& other){
		return w<other.w;
	}
};
vector<Edge> edges;
vector<int> p;
int getP(int a){
	return (a==p[a]? a:p[a]=getP(p[a]));
}
void unite(int a,int b){
	a=getP(a),b=getP(b);
	if(a==b) return;
	p[a]=b;
}
int n,m;
int kruskal(){
	int u,v,w,cnt;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		edges.push_back({u,v,w});
	}

	int ans=1000000000;
	sort(edges.begin(),edges.end());
	for(int i=0;i<m;i++){
		for(int k=1;k<=n;k++) p[k]=k;
		unite(edges[i].u,edges[i].v);
		cnt=1;
		for(int j=i+1;j<m;j++){
			if( getP(edges[j].u)!=getP(edges[j].v) ){
				unite(edges[j].u,edges[j].v);
				cnt++;	
			}
			if(cnt==n-1){
				ans = min(ans,edges[j].w-edges[i].w);	
				break;
			}
		}
	}
	if(n==2) return 0;
	if(ans==1000000000) return -1;
	return ans;
}
void solve(){
}
int main(){
    fio();
	int ans;
	while(cin>>n>>m){
		if(n==0&&m==0)
			break;
		if( m==0 ) cout<<"-1"<<endl;
		else{
			edges.clear();
			p.resize(n+1);
			ans = kruskal();
			cout<<ans<<endl;
		}
	}

}












