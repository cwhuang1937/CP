#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);


    int n, m;
    while(cin >> n >> m){
        map<int, vector<int>> M;

        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            M[num].push_back(i);
        }
        while (m--)
        {
            int k, v;
            cin >> k >> v;
            if (M.count(v) && M[v].size() >= k)
            {
                cout << M[v][k-1] + 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}