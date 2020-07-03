#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int g[200010], sum[200010], cnt[200010];

int Find(int a) {
    if(g[a] == a)
        return a;
    return g[a] = Find(g[a]);
}
void Union(int a, int b) {
    int ga = Find(a);
    int gb = Find(b);
    if(ga != gb) {
        g[ga] = gb;
        sum[gb] += sum[ga];
        cnt[gb] += cnt[ga];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, op, a, b;
    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) {
            g[i] = g[i+n] = i+n;
            sum[i+n] = i;
            cnt[i+n] = 1;
        }
        while(m--) {
            cin >> op;
            if(op == 1) {
                cin >> a >> b;
                Union(a, b);
            }
            else if(op == 2) {
                cin >> a >> b;
                int ga = Find(a);
                int gb = Find(b);
                if(ga != gb) {
                    g[a] = gb;
                    sum[gb] += a;
                    sum[ga] -= a;
                    cnt[gb]++;
                    cnt[ga]--;                          
                }            
            }
            else {
                cin >> a;
                int ga = Find(a);
                cout << cnt[ga] << " " << sum[ga] << "\n";
            }
        }
    }
    
    return 0;
}