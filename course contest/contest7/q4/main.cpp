#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N,m;
    cin>>N>>m;
    vector<int> A;
    A.resize(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    int maxn = A[A.size()-1];
    
    long long int total=0;
    for(int i=0;i<N;i++){
        total+=maxn-A[i];
    }
    if( m<= total) cout<<maxn<<endl;
    else{
        m-=total;
        if(m%N!=0)
            cout<<maxn+(m/N)+1<<endl;
        else 
            cout<<maxn+(m/N)<<endl;
    }
    


    return 0;
}