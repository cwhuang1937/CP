#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k)
    {
        int n, b;
        vector<int> V;
        cin >> n >> b;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            V.push_back(num);
        }
        sort(V.begin(), V.end());
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(b >= V[i]){
                count++;
                b -= V[i];
            }
            else
                break;
        }
        cout << "Case #" << k << ": " << count << "\n";
    }

    return 0;
}