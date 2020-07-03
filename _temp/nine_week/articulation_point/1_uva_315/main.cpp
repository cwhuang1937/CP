#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
const int MAXN = 2e5 + 5;
const int INF = 1e9;
typedef pair<int,int> P;




int n; //number of nodes
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin,low;
int timer;
int ans;
vector<int> record;

void dfs(int v,int p=-1){
	visited[v] = true;
	tin[v] = low[v] = timer++;
	int children=0;
	for(int to: adj[v]){
		if( to==p ) continue;
		if(visited[to]) low[v] = min(low[v],tin[to]);
		else {
			dfs(to,v);
			low[v] = min(low[v],low[to]);
			if( low[to]>=tin[v] && p!=-1){
				if( record[v]==-1){
					ans++;
					record[v] = 1;
				}
			}
			++children;
		}
	}
	if( p==-1 && children>1 ){
		if( record[v]==-1){
			record[v] = 1;
			ans++;
		}
	}
}
int find_cutpoints(){
	ans = 0;
	timer = 0;
	record.assign(n,-1);
	visited.assign(n,false);
	tin.assign(n,-1);
	low.assign(n,-1);
	for(int i=0;i<n;i++){
		if( !visited[i] )
			dfs(i);
	}
	return ans;
}
int main(){
    fio();
	int a,b;
	string line;
	while(cin>>n && n){
		cin.ignore();
		adj.clear();
		adj.resize(n);
		while( getline(cin,line) ){
			if( line=="0" ) break;
			stringstream ss(line);
			ss>>a,a--;
			while(ss>>b){
				b--;
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
		}
		cout<<find_cutpoints()<<endl;
	}


}












