#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long h, w;
    cin >> h >> w;

    if(h == 1 && w == 1)
        cout << 1 << '\n';
    else if(h == 1 || w == 1)
        cout << 1 << '\n';
    else if((h*w) % 2 == 0)
        cout << (h * w)/2 << '\n';
    else
        cout << (h * w)/2 + 1 << '\n';
    return 0;
}