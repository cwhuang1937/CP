#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int mxN = 6;
int n;
int a[mxN], b[mxN];

void mergesort(int l, int r) { // [l, r)
    if(r-l <= 1)
        return;

    int m = (l+r)/2;
    mergesort(l, m);
    mergesort(m, r);

    copy(a+l, a+r, b+l);

    int p = l;
    int q = m;
    int t = l;
    while(t < r) {
        if(q == r || (p != m && b[p] <= b[q]))
            a[t++] = b[p++];
        else
            a[t++] = b[q++];
    }
}




int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    mergesort(0, n);    

    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";

    return 0;
}