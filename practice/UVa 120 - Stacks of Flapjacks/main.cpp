#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    int n, maxidx, idx;
    
    while(getline(cin, s)) {
        vector<int> V, V2, out, res;
        stringstream ss(s);
        while(ss >> n)
            V.push_back(n);

        
        
        out = V;
        V2 = V;
        sort(V2.begin(), V2.end());
        idx = V2.size()-1;
        maxidx = 0;
        while(1) {
            if(idx < 0)
                break;
            for(int i = 0; i < V.size(); ++i) {
                if(V[i] == V2[idx]) {
                    maxidx = i;
                    break;
                }
            }
            if(maxidx == idx) {
                idx--;
                continue;
            }
            if(maxidx != 0){ // maxidx in the middle
                for(int i = 0; i < (maxidx+1)/2; ++i)
                    swap(V[i], V[maxidx-i]);
                res.push_back(V.size()-maxidx);
                maxidx = 0;
            }
            if(maxidx == 0) { // maxidx in the left
                for(int i = 0; i < (idx+1)/2; ++i)
                    swap(V[i], V[idx-i]);
                res.push_back(V.size()-idx);
            }
            idx--;
        }
        for(int i = 0; i < out.size()-1; ++i)
            cout << out[i] << " ";
        cout << out[out.size()-1] << "\n";

        for(int i : res)
            cout << i << " ";
        cout << 0 << "\n";
    }
    return 0;
}