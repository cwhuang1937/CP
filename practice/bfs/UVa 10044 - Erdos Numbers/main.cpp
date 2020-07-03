#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
using namespace std;


struct point {
    int pos, dist;
};
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, P, N;
    string s;
    cin >> t;
    for(int k = 1; k <= t; ++k) {
        cin >> P >> N;
        cout << "Scenario " << k << "\n";
        getline(cin, s);
        unordered_map<string, int> M;
        unordered_map<int, vector<point>> E;
        int idx = 1;
        
        while(P--) {
            getline(cin, s);
            stringstream ss(s);
            vector<int> rec;
            int cnt = 0;
            string s2 = "";     
            bool f = 0;
            while(ss >> s) {
                if(cnt == 1) {
                    s2 += s;
                    if(s2[s2.length()-1] == ':')                 
                        f = 1;
                    
                    s2 = s2.substr(0, s2.length()-1);
                    if(!M.count(s2))
                        M[s2] = idx++;   
                    rec.push_back(M[s2]);
                    s2 = "";
                    cnt = 0;
                    if(f)
                        break;            
                }
                else {
                    s2 += s + " ";
                    cnt++;
                }
            }
            for(int i = 0; i < rec.size(); ++i) {
                for(int j = i+1; j < rec.size(); ++j) {
                    E[rec[i]].push_back({rec[j], INT_MAX});
                    E[rec[j]].push_back({rec[i], INT_MAX});
                }
            }
        }
        

        // for(auto it = M.begin(); it != M.end(); ++it)
        //     cout << it->F  <<  " " << it->S <<  "\n";
        // cout << "\n";

        int res[idx];
        for(auto & i : res)
            i = INT_MAX;
        queue<point> Q;
        // for(auto p : E[M["Erdos,P."]])
        //     cout << p.pos << "\n";
        if(M.count("Erdos, P."))
            Q.push({M["Erdos, P."], 0});
        while(!Q.empty()) {
            point p = Q.front();
            Q.pop();
            int u = p.pos;
            int d = p.dist;
      
            for(auto v : E[u]) {
                if(res[v.pos] != INT_MAX)
                    continue;
                res[v.pos] = d+1;
                // cout << v.pos << " " << d+1 << "\n";
                Q.push({v.pos, d+1});
            }
        }
        while(N--) {
            getline(cin, s);
            stringstream ss(s);
            string target = "";
            while(ss >> s)
                target += s + " ";
            target = target.substr(0, target.length()-1);
            // cout << target << "\n";
            if(res[M[target]] == INT_MAX)
                cout << target << " infinity\n";
            else
                cout << target << " " << res[M[target]] << "\n";

        }
    }
    return 0;
}