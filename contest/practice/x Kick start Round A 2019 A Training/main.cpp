#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int k=1; k<=T; ++k) {
        int N, P;
        vector<int> V;
        cin >> N >> P;
        for(int i=0; i<N; ++i) {
            int in;
            cin >> in;
            V.push_back(in);
        }
        sort(V.begin(), V.end(), [](int a, int b){return a > b;});


        int minn = 10001;
        for(int i=0; (i+P)<=V.size(); ++i) {
            int sum = 0;
            for(int j=i; j<i+P-1; ++j) {                        
                sum += (V[i+P-1] - V[j]);
            }
            
            minn = min(minn, sum);
        }
        cout << "Case #" << k << ": " << minn << '\n';
    }

    
    return 0;
}