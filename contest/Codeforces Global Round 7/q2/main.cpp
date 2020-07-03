#include<bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    cin >> n;

    long long a[n];
    long long b[n];
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    a[1] = b[1];
    a[2] = b[1] + b[2];
    long long maxa = max(a[1], a[2]);
    for (int i = 3; i <= n; ++i) {
        a[i] = b[i] + maxa;
        maxa = max(maxa, a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << '\n';
    return 0;
}