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
        cin >> N >> K;
        vector<string> V;
        bool flag[N] = {false};
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            V.push_back(s);
        }
        int total = 0;
        for (int i = 0; i < N-1; ++i) {
            if(flag[i])
                continue;

            int sum = 0;
            int index = 0;
            for (int j = i+1; j < N; ++j) {
                int count = 0;
                for(int k = 0; k < min(V[i].length(), V[j].length()); ++k) {
                    if(V[i][k] == V[j][k])
                        count++;              
                    else
                        break;
                }
                if(count > sum) {
                    index = j;
                    sum = count;
                }
            }
            flag[index] = true;
            total += sum;
        }
        cout << "Case #" << l << ": " << total << "\n";
    }

    return 0;
}