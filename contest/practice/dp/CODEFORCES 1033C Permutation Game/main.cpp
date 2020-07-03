#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    const int maxn = 1e5 + 10;
    cin >> n;

    int idx[maxn];
    int arr[maxn];
    bool ans[maxn] = {false};
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        idx[arr[i]] = i;
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = idx[i]; j <= n; j+=i) {     
            if(arr[j] > i && !ans[j]) {
                ans[idx[i]] = true;
            }
        }
        for (int j = idx[i]; j >= 1; j-=i) {     
            if(arr[j] > i && !ans[j]) {
                ans[idx[i]] = true;
            }
        }

    }
    for (int i = 1; i <= n; ++i) {
        if(ans[idx[arr[i]]])
            cout << "A";
        else
            cout << "B";
    }
    cout << '\n';
    return 0;
}