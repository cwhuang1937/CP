#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
const int MAXN = 2e5 + 5;
struct Edge{
	int u,v;
	double weight;
	bool operator<(Edge const& other){
		return weight < other.weight;
	}
};
int N;
int n,cost,s;
vector<Edge> edges;
vector<Edge> result;
vector<int> tree_id;
vector<pair<int,int>> p;
void solve(){
	int a,b,c,d;
	double wei;
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			a=p[i].first,b=p[i].second,c=p[j].first,d=p[j].second;
			wei = sqrt(pow(abs(a-c),2)+pow(abs(b-d),2));
			struct Edge f;
			f.u=i,f.v=j,f.weight=wei,edges.push_back(f);
		}
	}
	for(int i=0;i<n;i++)
		tree_id[i]=i;
	sort(edges.begin(),edges.end());
	for(Edge e:edges){
		if(tree_id[e.u]!=tree_id[e.v]){
			cost+=e.weight;
			result.push_back(e);
			int old_id=tree_id[e.u],new_id=tree_id[e.v];
			for(int i=0;i<n;i++){
				if(tree_id[i]==old_id)
					tree_id[i]=new_id;
			}
		}
	}
	sort(result.rbegin(),result.rend());
	if(s<n) cout<<fixed<<setprecision(2)<<result[s-1].weight<<endl;
	else cout<<0<<endl;
}
int main(){
 	fio();
	int a,b;
	cin>>N;
	while(N--){
		cin>>s>>n;
		cost=0,tree_id.resize(n),edges.clear(),result.clear(),p.resize(n);
		solve();
	}
}












