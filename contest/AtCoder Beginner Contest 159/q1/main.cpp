#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int a, b;
    cin >> a >> b;
    cout << a*(a-1)/2 + b*(b-1)/2 << "\n";

    return 0;
}