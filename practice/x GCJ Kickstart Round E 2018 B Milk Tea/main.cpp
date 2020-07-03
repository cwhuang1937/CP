#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int k = 1; k <= t; ++k) {
        unsigned long int N, M, P;
        int ans = 0;
        int mins = 1000000;
        cin >> N >> M >> P;
        const unsigned long int P_C = P;
        string demand[N];
        string res[M];

        for(int i = 0; i < N; ++i)
            cin >> demand[i];
        for(int i = 0; i < M; ++i)
            cin >> res[i];
        
        for(int i = 0; i < (2<<P)-1; ++i) {
            bitset<P_C> bt(ans);
            string ans_s;
            ans_s = bt.to_string();
            cout << ans_s << '\n';
            int sum = 0;
            bool flag = false;
            for(int j = 0; j < M; ++j) {
                if(demand[j] == ans_s) {
                    ans++;
                    flag = true;
                    break;
                }
            }
            // if(flag)
            //     continue;

            // for(int j = 0; j < P; ++j) {
            //     if(demand[j] != ans_s[j]) {
            //         sum++;
            //     }
            // }
            
            // mins = min(mins, sum);
            ans++;
        }
        cout << "Case #" << k << ": " << mins << '\n'; 
    }
    

    return 0;
}