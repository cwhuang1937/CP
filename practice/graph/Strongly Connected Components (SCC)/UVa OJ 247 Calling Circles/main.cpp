#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

vector<int> g[30], gr[30];
vector<int> order, compo;
bool vis[30];
unordered_map<string, int> M;
string rec[30];

void dfs1(int u) {
    vis[u] = 1;
    for(auto v : g[u])
        if(!vis[v])
            dfs1(v);
    order.push_back(u);
}
void dfs2(int u) {
    vis[u] = 1;
    compo.push_back(u);
    for(auto v : gr[u])
        if(!vis[v])
            dfs2(v);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, idx, t = 1, cnt;
    string s1, s2;
    while(cin >> n >> m) {
        if(n == 0)
            break;
        if(t != 1)
            cout << "\n";
        cout << "Calling circles for data set " << t++ << ":\n";
        idx = 0;
        for(int i = 0; i < n; ++i) {
            g[i].clear();
            gr[i].clear();
            rec[i] = "";
        }
        cnt = 1;
        M.clear();
        order.clear();
        for(int i = 0; i < m; ++i) {
            cin >> s1 >> s2;
            if(!M.count(s1))
                M[s1] = idx++;
            if(!M.count(s2))
                M[s2] = idx++;
            g[M[s1]].push_back(M[s2]);
            gr[M[s2]].push_back(M[s1]);
            rec[M[s1]] = s1;
            rec[M[s2]] = s2;
        }
        for(int i = 0; i < n; ++i)
            vis[i] = 0;
        for(int i = 0; i < n; ++i)
            if(!vis[i])
                dfs1(i);

        reverse(order.begin(), order.end());

        for(int i = 0; i < n; ++i)
            vis[i] = 0;
        for(auto v : order) {
            if(!vis[v]) {
                dfs2(v);
                if(cnt != 1)
                    cout << "\n";
                cnt++;
                for(int i = 0; i < compo.size()-1; ++i)
                    cout << rec[compo[i]] << ", ";
                cout << rec[compo[compo.size()-1]];
                compo.clear();
            }
        }
        cout << "\n";
    }
    return 0;
}