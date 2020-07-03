#include <bits/stdc++.h>
using namespace std; 

#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;

//str.substr(pos,number) str.insert(str.begin()+5,'3')
//set.insert(num) set.count(i)!=0
int n,m;
const int maxn = 20+5;
const int maxm = 100+5;
const int INF = 1e9;
char s1[maxn],s2[maxn];
int post1[maxm],post2[maxm],negt1[maxm],negt2[maxm],times[maxm];
typedef pair<int,int> P;
int d[1<<maxn];


void change(char *c1,char *c2,int num){

	for(int i=0;i<n;i++){
		if( c1[i]=='+' ) post1[num]=post1[num]|(1<<i);
		if( c1[i]!='-' ) negt1[num]=negt1[num]|(1<<i);
	}
	for(int i=0;i<n;i++){
		if( c2[i]=='+' ) post2[num]=post2[num]|(1<<i);
		if( c2[i]!='-' ) negt2[num]=negt2[num]|(1<<i);
	}

}
void dijkstra(){
	priority_queue<P,vector<P>,greater<P> > pq;
	fill(d,d+(1<<n),INF);
	int s=(1<<n)-1;
	d[s]=0;
	pq.push(P(0,s));

	while( !pq.empty() ){
		P p=pq.top();
		pq.pop();
		int v=p.second;
		if(d[v]<p.first) continue;
		if( v==0 ) break;

		for(int i=0;i<m;i++){
			if( ((v|post1[i])==v) && ((v&negt1[i])==v) ){
				int next=v;
				next=next|post2[i];
				next=next&negt2[i];
				if( d[next]>d[v]+times[i] ){
					d[next]=d[v]+times[i];
					pq.push(P(d[next],next));
				}
			}
		}


	}


}



int main(){
    fio();
	int t=1;
	while( cin>>n>>m){
		if(n==0&&m==0) break;
		memset(post1,0,sizeof(post1));
		memset(post2,0,sizeof(post2));
		memset(negt1,0,sizeof(negt1));
		memset(negt2,0,sizeof(negt2));
		for(int i=0;i<m;i++){
			cin>>times[i]>>s1>>s2;
			change(s1,s2,i);
		}
		dijkstra();
		cout<<"Product "<<t++<<endl;
		if( d[0]==INF ) cout<<"Bugs cannot be fixed."<<endl<<endl;
		else cout<<"Fastest sequence takes "<<d[0]<<" seconds."<<endl<<endl;

	}

}












