#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int n;
bool vis[20];
vector<int> res;

bool isp(int a) {
    for(int i = 2; i*i <= a; ++i)
        if(a%i == 0)
            return false;
    return true;
}
void dfs(int dep) {
    if(dep == n-1) {
        if(isp(res[dep]+1)) {
            for(int i = 0; i < res.size()-1; i++)
                cout << res[i] << " ";
            cout << res[dep] << "\n";
        }
        return;
    }
    for(int i = 2; i <= n; ++i) {
        if(vis[i] || !isp(res[dep]+i))
            continue;

        vis[i] = true;
        res.push_back(i);
        dfs(dep+1);    
        vis[i] = false;
        res.pop_back();                                                 
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int idx = 1;
    res.push_back(1);
    while(cin >> n) {
        if(idx != 1)
            cout << "\n";
        cout << "Case " << idx++ << ":\n";
        for(bool &b : vis)
            b = false;
 
        dfs(0);
    }
    
    return 0;
}