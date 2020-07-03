#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
// const int MAXN = 30+5;
const int INF = 1e9;
typedef pair<int,int> P;
int n;
void solve(){
	vector<vector<int>> d(n,vector<int> (n,INF));
	int a;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a;
			if( a!=0 ) d[i][j] = a;
        }
    }
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);	
			}
		}
	}
	int ans=INF;
	//detect ring
	for(int k=0;k<n;k++){
		ans=min(ans,d[k][k]);
	}
	if( ans != INF) cout<<ans<<endl;
	else cout<<-1<<endl;
	


}
int main(){
    fio();
	while(cin>>n&&n){
    	solve();
	}
}