#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+50;

string s;
char str[MAXN*2];
int Len[MAXN*2],len,TP,GR;

void initStr(int l,int r){
    int k=0;
    str[k++]='@';
    for(int i=l;i<=r;i++){
        str[k++]='#';
        str[k++]=s[i];
    }
    str[k++]='#';
    len=k;
    str[k]='\0';
}

void manacher(){
    int mx=0,id=0;
    for(int i=1;i<len;i++){
        if(mx>i)
            Len[i]=min(mx-i,Len[2*id-i]);
        else
            Len[i]=1;
        while(str[i+Len[i]]==str[i-Len[i]])
            Len[i]++;
        if(Len[i]+i>mx){
            mx=Len[i]+i;
            id=i;
        }
        
        if(i==Len[i])
            if(TP<Len[i])
                TP=Len[i]-1,GR=1;
        if(i+Len[i]==len)
            if(TP<Len[i])
                TP=Len[i]-1,GR=2;
    }
}

void solve()
{
    cin>>s;
    int LEN=s.size();
    
    int L=0,R=LEN-1;
    while(L<R&&s[L]==s[R])
        L++,R--;
    
    if(L>=R)
    {
        cout<<s<<'\n';
        return;
    }
    
    initStr(L,R);
    TP=0;
    manacher();
    for(int i=0;i<L;i++)
        cout<<s[i];
    if(GR==1)
    {
        for(int i=L,j=0;j<TP;i++,j++)
            cout<<s[i];
    }
    else
    {
        for(int i=R-TP+1;i<=R;i++)
            cout<<s[i];
    }
    for(int i=R+1;i<LEN;i++)
        cout<<s[i];
    
    cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--)
        solve();
    
    return 0;
}