#include<bits/stdc++.h>
using namespace std;

int main() {
    set<int> S;
    int n;
    cin >> n; 

    while(!S.count(n)) {
        S.insert(n);
        ++n;
        while(n%10 == 0)
            n /= 10;
    }
    cout << S.size() << '\n';
    return 0;
}