#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
const int MAXN = 30+5;
const int INF = 1e9;
typedef pair<int,int> P;
int nums,cases;
void solve(){
	vector<vector<int>> d(MAXN,vector<int> (MAXN,INF));
	vector<vector<int>> ans(MAXN,vector<int> (MAXN,0));	
	int a,b,n=-1;
	for(int i=0;i<nums;i++){
		cin>>a>>b;
		n = max(max(a,b),n);
		d[a][b] = 1;
		ans[a][b]++;
	}
	n+=1;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if( d[i][k]!=INF && d[k][j]!=INF )
					ans[i][j]+=ans[i][k]*ans[k][j];
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);	
			}
		}
	}
	//detect ring
	for(int k=0;k<n;k++){
		if( d[k][k]!=INF ){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if( d[i][k]!=INF && d[k][j]!=INF )
						ans[i][j] = -1;
				}
			}
		}
	}

	cout<<"matrix for city "<<cases++<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if( j!=n-1 ) cout<<ans[i][j]<<" ";
			else cout<<ans[i][j];
		}
		cout<<endl;
	}
	
	


}
int main(){
    fio();
	while(cin>>nums){
    	solve();
	}
}












