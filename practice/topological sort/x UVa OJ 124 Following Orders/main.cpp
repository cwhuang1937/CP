#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string str, s1, s2;
    while(getline(cin, str)) {
        
        unordered_map<string, int> Deg;
        unordered_map<string, vector<string>> E;
        queue<string> Q;
        vector<string> res;


        stringstream ss1, ss2;
        ss1 << str;
        while(ss1 >> s1)
            Deg[s1] = 0;
        

        getline(cin, str);  
        ss2 << str;
        
        while(ss2 >> s1 >> s2) {
            Deg[s2]++;
            E[s1].push_back(s2);
        }
        
    
        for(auto it = Deg.begin(); it != Deg.end(); ++it)
            if(it->second == 0)
                Q.push(it->first);
           


        while(!Q.empty()) {
            s1 = Q.front();
            Q.pop();
            res.push_back(s1);

            for(int i = 0; i < E[s1].size(); ++i) {
                s2 = E[s1][i];
                Deg[s2]--;
                if(Deg[s2] == 0)
                    Q.push(s2);
            }
        }

        for(int i = 0; i < res.size(); ++i)
            cout << res[i];
        cout << "\n";
        

    }
    return 0;
}