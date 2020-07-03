#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int gcd(int a, int b) {
    return a ? gcd(b%a, a) : b;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b;
    while(cin >> a) {
        if(a == 0)
            break;
        vector<int> V;
        V.push_back(a);
        while(cin >> b) {
            if(b == 0)
                break;
            V.push_back(b);
        }
        int d = *min_element(V.begin(), V.end());
        for(auto &i : V)
            i -= d;
        
        a = V[0];
        for(int i = 1; i < V.size(); ++i)
            a = gcd(a, V[i]);
        
        cout << a << "\n";

    }   
    
    return 0;
}