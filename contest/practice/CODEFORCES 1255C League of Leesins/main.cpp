#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int main() {
    map<pair<int, int>, vector<int>> M;
    int n, x, y, z;;
    int cnt[maxn] = {};
    cin >> n;

    for(int i = 0; i < n-2; ++i) {
        
        cin >> x >> y >> z;

        M[{x, y}].push_back(z);
        M[{y, x}].push_back(z);
        M[{x, z}].push_back(y);
        M[{z, x}].push_back(y);
        M[{y, z}].push_back(x);
        M[{z, y}].push_back(x);
        
        cnt[x]++;
        cnt[y]++;
        cnt[z]++;
    }
    int p1, p2;
    for(int i = 1; i <= n; ++i) {
        if(cnt[i] == 1) {
            p1 = i;
            break;
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(cnt[i] == 2 && M.count({p1, i})) {
            p2 = i;
            break;
        }
    }

    cout << p1 << " " <<  p2 << " "; 
    bool vis[maxn] = {};
    for(int i = 0; i < n-2; ++i) {
        map<pair<int, int>, vector<int>>::iterator it;
        it = M.find({p1, p2});

        if(it != M.end()) {
            vis[p1] = true;
            p1 = p2;
            if(vis[it->second[0]])
                p2 = (it->second)[1];
            else
                p2 = (it->second)[0];
            cout << p2 << " ";
        } 
    }
    return 0;
}