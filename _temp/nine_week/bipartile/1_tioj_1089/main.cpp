#include <bits/stdc++.h>
using namespace std;
#define N 500

vector<int> X[N+5],Y[N+5];
int fX[N+5], fY[N+5];
bitset<N+5> walked;

bool dfs(int);

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;++i)fX[i]=fY[i]=-1;
	while(k--){
		int s,e;cin>>s>>e;
		X[s].push_back(e);
		Y[e].push_back(s);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		walked.reset();
		if(dfs(i))ans++;
	}
	cout<<ans;
	return 0;
}

bool dfs(int x){
	for(auto i:X[x]){
		if(walked[i])continue;
		walked[i]=1;
		if(fY[i]==-1||dfs(fY[i])){ //fy[i]代表之前與i建立關係的左邊那個點 
            //dfs(fy[i]) 想辦法從fy[i]找到augmenting path
			fY[i]=x;fX[x]=i; //將兩點建立關係相連
			return 1;
		}
	}
	return 0;
}