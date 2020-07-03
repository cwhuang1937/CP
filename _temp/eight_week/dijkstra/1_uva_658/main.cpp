#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
const int MAXN = 2e5 + 5;
const int INF = 1000000000;
int n,m,s,t,T;
vector<vector<pair<int,int>>> adj;
vector<int> p;
vector<int> d;
int cases;
void dijkstra(){
	long long int cost=0;
	adj.clear();
	adj.resize(n);
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
	}
	d.assign(n,INF);
	p.assign(n,-1);
	vector<bool> u(n, false);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push(make_pair(0,s));
	d[s]=0;
	//for(int i=0;i<n;i++){
	while( !pq.empty() ){
		int v=pq.top().second;
		pq.pop();
		//for(int j=0;j<n;j++){
	//		if(!u[j] && (v==-1||d[j]<d[v]) ) v=j;
//		}

		if(d[v]==INF) break;
		
		u[v] = true;
		for(auto edge: adj[v]){
			int to=edge.first;
			int len=edge.second;
			if(d[v]+len < d[to]){
				d[to]=d[v]+len;
				p[to]=v;
				pq.push(make_pair(d[to],to));
			}
		}
	}
	cout<<"Case #"<<++cases<<": ";
	if( d[t]==INF ) cout<<"unreachable"<<endl;
	else cout<<d[t]<<endl;
	
	//vector<int> path;
	//for(int v=t;v!=s;v=p[v]) path.push_back(v);
	//path.push_back(s);
	//reverse(path.begin(),path.end());

}

void solve(){
}
int main(){
    fio();
	cin>>T;
	while(T--){
		cin>>n>>m>>s>>t;
		dijkstra();
		
	}
    solve();

}












