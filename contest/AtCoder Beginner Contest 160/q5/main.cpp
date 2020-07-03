#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    // vector<int> va(a), vb(b), vc(c);
    // for(int i = 0; i < a; ++i)
    //     cin >> va[i];
    // for(int i = 0; i < b; ++i)
    //     cin >> vb[i];
    // for(int i = 0; i < c; ++i)
    //     cin >> vc[i];
    // sort(va.begin(), va.end(), greater<int>());
    // sort(vb.begin(), vb.end(), greater<int>());
    // sort(vc.begin(), vc.end(), greater<int>());
    vector<pair<int, int>> V;
    vector<int> Vc;
    int num;
    for(int i = 0; i < a; ++i){
        cin >> num;
        V.push_back(make_pair(0, num));
    }
    for(int i = 0; i < b; ++i){
        cin >> num;
        V.push_back(make_pair(1, num));
    }
    for(int i = 0; i < c; ++i){
        cin >> num;
        V.push_back(make_pair(2, num));
    }
    sort(V.begin(), V.end(), [](pair<int, int> p1, pair<int, int> p2){return p1.second > p2.second;});

    // cout << V.begin()->first << " " << V.begin()->second << "\n";
    ll total = 0;
    ll cnx = x;
    ll cny = y;
    for(int i = 0; i < a+b+c; ++i) {
        if((cnx == 0 && cny == 0) || cnx+cny == Vc.size())
            break;

        if(V[i].first == 0 && cnx > 0) {
            total += V[i].second;
            cnx--;
        }
        else if(V[i].first == 1 && cny > 0) {
            total += V[i].second;
            cny--;
        }
        else if(V[i].first == 2){
            Vc.push_back(V[i].second);
        }      
    }
    for(int i = 0; i < Vc.size(); i++){
        total += Vc[i];
    }
    cout << total << "\n";
    

    

    return 0;
}