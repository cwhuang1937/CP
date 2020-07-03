#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
const int MAXN = 105;
const int INF = 1e9;
int n,s,t;
int T[6];
int w[MAXN][MAXN];
int d[MAXN];
int F[MAXN];


void Dijkstra(){
	s=0;
	priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	d[s] = 0;
	pq.push(make_pair(0,d[s]));
	while( !pq.empty() ){
		int v=pq.top().second;
		pq.pop();
		if( d[v]==INF ) break;
		
		for(int i=0;i<MAXN;i++){
			if( d[i]>d[v]+w[v][i]+60 ){
				d[i] = d[v]+w[v][i]+60;
				pq.push(make_pair(d[i],i));
			}
		}
	}
	if( t==0 ) cout<<0<<endl;
	else if( d[t]==INF ) cout<<"IMPOSSIBLE"<<endl;
	else cout<<d[t]-60<<endl;




}
int main(){
    fio();
	string str;
	int a,cnt;
	while( cin>>n>>t ){
		//initial the graph
		for(int i=0;i<MAXN;i++)
			for(int j=0;j<MAXN;j++)
				w[i][j] = INF;
		for(int i=0;i<MAXN;i++) d[i] = INF;
		//read the T
		for(int i=0;i<n;i++) cin>>T[i];
		//read the elevator
		cin.ignore();
		for(int i=0;i<n;i++){
			cnt=0;
			getline(cin,str);
			stringstream ss(str);
			while( ss>>F[cnt]) cnt++;
			
			for(int k=0;k<cnt;k++){
				for(int j=k+1;j<cnt;j++){
					if( (F[j]-F[k])*T[i]<w[F[k]][F[j]] ){
						w[F[j]][F[k]] = w[F[k]][F[j]] = (F[j]-F[k])*T[i];	
					}
				}
			}
		}

		Dijkstra();
	}

}












