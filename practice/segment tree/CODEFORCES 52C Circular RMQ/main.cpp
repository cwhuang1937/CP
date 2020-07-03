#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

#define mxN 200005
struct node {
    ll res;
    ll tag;
    node() {
        res = INT_MAX;
        tag = 0;
    }
};
node seg[mxN*4]; // 4倍較安全
ll a[mxN];
void push(int n, int l, int r) {
    int m = (l+r)/2;
    int lc = 2*n;
    int rc = 2*n+1;
    ll tag = seg[n].tag;
    
    seg[lc].tag += tag;
    seg[rc].tag += tag;
    seg[lc].res += tag;
    seg[rc].res += tag;
    
    seg[n].tag = 0; 
}
void update(int l, int r, int ql, int qr, ll val, int n) {
    if(l >= qr || r <= ql)
        return;
    if(l >= ql && r <= qr) {
        seg[n].res += val;
        seg[n].tag += val;
        return;
    }
    push(n, l, r);
    int m = (l+r)/2;
    int lc = 2*n;
    int rc = 2*n+1;
    update(l, m, ql, qr, val, lc);
    update(m, r, ql, qr, val, rc);

    seg[n].res = min(seg[lc].res, seg[rc].res);  
}
ll query(int l, int r, int ql, int qr, int n) {
    if(r <= ql || l >= qr)
        return INT_MAX;
    if(l >= ql && r <= qr)
        return seg[n].res;
    
    push(n, l, r);
    int m = (l+r)/2;
    int lc = 2*n;
    int rc = 2*n+1;

    return min(query(l, m, ql, qr, lc), query(m, r, ql, qr, rc));
}
void build(int l, int r, int n) {
    if(r-l == 1) {
        seg[n].res = a[l];
        return;
    } 
    int m = (l+r)/2;
    int lc = 2*n;
    int rc = 2*n+1;
    build(l, m, lc);
    build(m, r, rc);

    seg[n].res = min(seg[lc].res, seg[rc].res);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    ll n, m, val, l, r;
    cin >> n;;
    
    for(int i = 1; i <= n; ++i)
        cin >> a[i];      
    build(1, n+1, 1);

    cin >> m;
    string s;
    getline(cin, s);
    
    while(m--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        ss >> l >> r;
        if(ss >> val) {
            if(l > r) {
                update(1, n+1, l+1, n+1, val, 1);  
                update(1, n+1, 1, r+2, val, 1);    
            }
            else
                update(1, n+1, l+1, r+2, val, 1);   
        }
        else {
            if(l > r)
                cout << min(query(1, n+1, l+1, n+1, 1), query(1, n+1, 1, r+2, 1)) << "\n";
            else
                cout << query(1, n+1, l+1, r+2, 1) << "\n";
        }



    }
    return 0;
}