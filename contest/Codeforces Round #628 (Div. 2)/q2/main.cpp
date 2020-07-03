#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        set<int> s;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int ele;
            cin >> ele;
            s.insert(ele);
        }
        cout << s.size() << '\n';
    }
    
    
    return 0;
}