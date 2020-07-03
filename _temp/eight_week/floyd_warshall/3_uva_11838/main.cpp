#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
// const int MAXN = 30+5;
const int INF = 1e9;
typedef pair<int,int> P;
int n,m;
void solve(){
	vector<vector<int>> d(n,vector<int> (n,INF));
	int a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		if( c==2 ) d[b-1][a-1] = 1;
		d[a-1][b-1]=1;
	}

	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);	
			}
		}
	}
	bool ans=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(d[i][j]==INF){
				ans = false;
				break;
			}
		}
	}
	if( ans ) cout<<1<<endl;
	else cout<<0<<endl;
	


}
int main(){
    fio();
	while(cin>>n>>m){
		if(n==0&&m==0) break;
    	solve();
	}
}












