#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int x1 , y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int s1 = 0;
        int s2 = 0;
        s1 = abs(x1 - x3) + abs(y1 - y3);
        s2 = min(abs(x2 - x3), abs(y2 - y3)) + abs(abs(x2 - x3) - abs(y2 - y3));
        if(s1 == s2)
            cout << "Same time\n";
        else if(s1 < s2)
            cout << "First\n";
        else
            cout << "Second\n";
    }
    return 0;
}