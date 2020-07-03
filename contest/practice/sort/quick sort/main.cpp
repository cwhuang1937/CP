#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int mxN = 6;
int n;
int a[mxN], b[mxN];

int partition(int l, int r) {
    int p = a[r]; // choose the last element to be pivot
    int idx = l; // record the final position for pivot

    for(int i = l; i < r; ++i)
        if(a[i] <= p)
            swap(a[i], a[idx++]);
    
    swap(a[r], a[idx]);

    return idx;
}
void quicksort(int l, int r) { // [l, r]
    if(l >= r)
        return;

    int m = partition(l, r);
    quicksort(l, m-1);
    quicksort(m+1, r);
}




int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    quicksort(0, n-1);    

    for(int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";

    return 0;
}