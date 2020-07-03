#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=0;
    for (int x=a;x<=b;++x)
    {
        for (int y=b;y<=c;++y)
        {
            for (int z=c;z<=d;++z)
            {
                if(x+y>z)
                    ans++;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}