#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int mxN = 1e6+10;
int g[mxN];
int n;

int Find(int a) {
    if(a == g[a])
        return a;
    return g[a] = Find(g[a]);
}

void Union(int a, int b) {
    g[Find(a)] = Find(b);
    // if(g[a] == g[b])
    //     return;

    // for(int i = 1; i <= n; ++i) {
    //     if(g[i] == Find(a))
    //         g[i] = Find(b);
    // }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int t;
    cin >> t;

    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            g[i] = i;

        string s;


        // windows : \r\n
        // ubuntu : \n
        getline(cin, s); // for windows
        // cin.ignore(); // for ubuntu
        int i = 1;
        while(getline(cin, s)) {
            // if(s.empty()) { // for ubuntu
            //     break;
            // }
            if(s[0] == '\r') { // for windows
                break;
            }
            stringstream ss(s);
            
                         
            int a, b;
            while(ss >> a >> b)
                Union(a, b);
        }
        

        int cnt = 0;
        for(int i = 1; i <= n; ++i)
            if(i == g[i])
                cnt++;


        cout << cnt << "\n";
        if(t)
            cout << "\n";
    }

    return 0;
}