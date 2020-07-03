#include<bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    while(Q--) {
        float x1, x2, c1, c2;
        cin >> x1 >> x2 >> c1 >> c2;

        // cout << (c2*(x1+x2) - x1*c1) / x2 << '\n';
        printf("%f\n", (c2*(x1+x2) - x1*c1) / x2 );
    }
    return 0;
}