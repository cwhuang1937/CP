#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

const long long  INF = 3e18;
int n,m,s,t;
vector<vector<pair<int,int>>> adj;
vector<long long> d;
void dijkstra(){
	adj.clear();
	adj.resize(n);
	for(int i=0;i<m;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
	}
	d.assign(n,INF);
	vector<bool> u(n, false);
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	pq.push(make_pair(0,s));
	d[s]=0;
	while( !pq.empty() ){
		int v=pq.top().second;
		pq.pop();

		if(d[v]==INF) break;
		
		u[v] = true;
		for(auto edge: adj[v]){
			int to=edge.first;
			int len=edge.second;
			if(d[v]+len < d[to]){
				d[to]=d[v]+len;
				pq.push(make_pair(d[to],to));
			}
		}
	}
	for(int i=0;i<n;i++) cout<<d[i]<<" ";
	cout<<endl;

}

int main(){
    fio();
	cin>>n>>m;
	s = 0;
	dijkstra();

}












