// #include<bits/stdc++.h>
#include<iostream>
#define ll long long
#define ld long double
using namespace std;

#define mxN 100005
struct node {
    ll sum;
    ll tag;
    node() {
        sum = 0;
        tag = 0;
    }
};
node seg[mxN*4]; // 4倍較安全

void push(int n, int l, int r) {
    int m = (l+r)/2;
    int lc = 2*n;
    int rc = 2*n+1;
    ll tag = seg[n].tag;
    
    seg[lc].tag += tag;
    seg[rc].tag += tag;
    seg[lc].sum += tag*(m-l);
    seg[rc].sum += tag*(r-m);
    
    seg[n].tag = 0; 
}
void update(int l, int r, int ql, int qr, ll val, int n) {
    if(l >= qr || r <= ql)
        return;
    if(l >= ql && r <= qr) {
        seg[n].sum += val*(r-l);
        seg[n].tag += val;
        return;
    }
    push(n, l, r);
    int m = (l+r)/2;
    int lc = 2*n;
    int rc = 2*n+1;
    update(l, m, ql, qr, val, lc);
    update(m, r, ql, qr, val, rc);
    seg[n].sum = seg[lc].sum + seg[rc].sum;  
}
ll query(int l, int r, int ql, int qr, int n) {
    if(r <= ql || l >= qr)
        return 0;
    if(l >= ql && r <= qr)
        return seg[n].sum;
    
    push(n, l, r);
    int m = (l+r)/2;
    int lc = 2*n;
    int rc = 2*n+1;
    return query(l, m, ql, qr, lc) + query(m, r, ql, qr, rc);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    ll N, Q, val, l, r;
    char type;
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i) {
        cin >> val;
        update(1, N+1, i, i+1, val, 1);
    }

    while(Q--) {
        cin >> type;
        if(type == 'Q'){
            cin >> l >> r;
            cout << query(1, N+1, l, r+1, 1) << "\n";
        }
        else {
            cin >> l >> r >> val;
            update(1, N+1, l, r+1, val, 1);   
        }
    }
    return 0;
}