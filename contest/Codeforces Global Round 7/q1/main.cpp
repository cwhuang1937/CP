#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int num;
        int total = 0;
        cin >> num;
        if(num == 1) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0; i < num-1; ++i) {
            total += 5;
            if(i == num-2 && total % 3 == 0) {
                cout << 4;
                break;
            }
            cout << 5;
        }
        cout << 3 << '\n';
    }
    return 0;
}