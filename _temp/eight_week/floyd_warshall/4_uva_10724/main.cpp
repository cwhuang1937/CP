#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
const int MAXN = 50+5;
const int INF = 1e9;
typedef pair<int,int> P;
int n,m;
double d[MAXN][MAXN];
int used[MAXN][MAXN],x[MAXN],y[MAXN];


void solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			d[i][j] = 1e9,used[i][j] = 0;
		d[i][i]=0;
	}
	int a,b;
	for(int i=0;i<n;i++)  cin>>x[i]>>y[i];
	for(int i=0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		d[a][b] = d[b][a] = hypot(x[a]-x[b],y[a]-y[b]);
		used[a][b] = used[b][a] = 1;
	}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
	double ans=0;
	int rx=-1,ry=-1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if( used[i][j] ) continue;
			
			double dis = hypot(x[i]-x[j],y[i]-y[j]);
			double cuv = 0;
			for(int k=0;k<n;k++){
				for(int h=k+1;h<n;h++){
					double thr  = d[k][i]+d[j][h]+dis;
					double thr2 = d[k][j]+d[i][h]+dis; 
					cuv += d[k][h] - min( d[k][h],min(thr,thr2) );
				}
			}
			if( cuv>0 && cuv>ans+1e-10 )
				ans = cuv,rx=i,ry=j;
		}
	}
	if( ans>1e-8 ) //means ans != 0
		cout<<rx+1<<" "<<ry+1<<endl;
	else
		cout<<"No road required"<<endl;


}
int main(){
	while(cin>>n>>m){
		if( n==0&&m==0 ) break;
		solve();	

	}


}




