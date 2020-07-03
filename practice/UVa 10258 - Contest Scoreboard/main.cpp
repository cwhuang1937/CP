#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define MP make_pair
#define F first
#define S second
using namespace std;

// used for sort the contestant from their solved problems, penalty, and team number
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    if(a.S.F != b.S.F)
        return a.S.F > b.S.F;
    else if(a.S.F == b.S.F && a.S.S != b.S.S)
        return a.S.S < b.S.S;
    return a.F < b.F;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int t;
    string emp;
    cin >> t;
    getline(cin, emp); 
    getline(cin, emp);
    while(t--) {
        string s;
        bool vis[101] = {0}; // record if the contestant is participating
        int probs[101][10] = {0}; // record if the problem is solved
        int penas[101][10] = {0}; // record the penalty when incorrect
        int time[101] = {0}; // record the total time
        int sol[101] = {0}; // record the totla solved problen
        
        while(getline(cin, s)) {
            if(s == "") // read the next case
                break;
            int cont, prob, ti;
            string ty; 
            stringstream ss(s); // use stringstream to split the string and number
            ss >> cont >> prob >> ti >> ty;

            vis[cont] = 1; // record the contestant is participating
            if(ty == "C" && probs[cont][prob] == 0) { // correct for add the total solved problems and time
                sol[cont]++;
                probs[cont][prob]++;
                time[cont] += penas[cont][prob] + ti;
            }
            if(ty == "I") { // incorrect for add penalty
                penas[cont][prob] += 20;
            }
        }
        vector<pair<int, pair<int, int>>> res; // store the all of contestant's information
        for(int i = 1; i <= 100; ++i) {
            if(!vis[i])
                continue;
            res.push_back(MP(i, MP(sol[i], time[i])));
        }

        sort(res.begin(), res.end(), cmp); // sort all of the contestant
        for(int i = 0; i < res.size(); ++i) // output the result
            cout << res[i].F << " " << res[i].S.F << " " << res[i].S.S << "\n";
        if(t != 0)
            cout << "\n";
    }
    return 0;
}