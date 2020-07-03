#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    cin >> T;
    for (int l = 1; l <= T; ++l) {
        int N, K;
        vector<int> V;
        map<int, int, greater<int>> M;
        cin >> N >> K;
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            V.push_back(num);
        }
        for (int i = 0; i < N-1; ++i)
            M[V[i + 1] - V[i]]++;
        

        for (int i = 0; i < K; ++i) {
            int value = M.begin()->first;
            if(value == 1)
                break;
            if(M.begin()->second == 1)
                M.erase(value);
            else
                M[value]--;

            if(value % 2 == 1) {
                M[value / 2]++;
                M[value / 2 + 1]++;
            }               
            else
                M[value / 2] += 2;
        }
        // for(auto it = M.begin(); it != M.end(); ++it) {
        //     cout << it->first << ": " << it->second << "\n";
        // }
        cout << "Case #" << l << ": " << M.begin()->first << "\n";
    }

    return 0;
}