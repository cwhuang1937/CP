#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int st[3][100];
int idx[3] = {0};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    for (int l = 1; l <= t; ++l)
    {
        int n, k, p;
        vector<int> V;
        cin >> n >> k, p;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < k; ++j)
                cin >> st[i][j];

        for (int i = 0; i < p; ++i) {

        }
            cout << "Case #" << l << ": " << count << "\n";
    }

    return 0;
}