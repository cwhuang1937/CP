#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

#define mxN 1000000
int seg[mxN];
bool f[mxN];

void update(int n, int l, int r, int idx, int val) {
    if(r-l == 1) {
        seg[n] = val;
        f[n] = 1;
    }
    else {
        int m = (l+r)/2;
        int lc = 2*n;
        int rc = 2*n+1;
        if(idx < m)
            update(lc, l, m, idx, val); // left child        
        else
            update(rc, m, r, idx, val); // right child

        if(f[lc])
            seg[n] = seg[lc] | seg[rc];
        else
            seg[n] = seg[lc] ^ seg[rc];

        f[n] = !f[lc];    
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, a, b, val;
    cin >> n >> m;
    int N = 1<<n;
    for(int i = 1; i <= N; ++i) {
        cin >> val;
        update(1, 1, N+1, i, val);
    }
    while(m--) {
        cin >> a >> b;
        update(1, 1, N+1, a, b);
        cout << seg[1] << "\n";
    }
    return 0;
}

// #include<bits/stdc++.h>
// #define ll long long
// #define ld long double
// using namespace std;

// vector<int> V(1000000);
// struct node {
//     int res;
//     bool f;
//     node *lc, *rc;
//     node() {
//         res = 0;
//         f = 1;
//         lc = rc = NULL;
//     }
// };
// node* build(int L, int R) {
//     node* u = new node();
//     if(R-L == 1) {
//         u->res = V[L];
//     } 
//     else {
//         int M = (L+R)/2;
//         u->lc = build(L, M);
//         u->rc = build(M, R);

//         if(u->lc->f) {
//             u->res = u->lc->res | u->rc->res;
//             u->f = 0;
//         }
//         else {
//             u->res = u->lc->res ^ u->rc->res;
//             u->f = 1;
//         }
//     }
//     return u;
// }
// void update(node* u, int L, int R, int pos, int val) {
//     if(pos < L || pos >= R)
//         return;
//     if(R-L == 1) {
//         u->res = val;
//         return;
//     }  
//     int M = (L+R)/2;
//     update(u->lc, L, M, pos, val);
//     update(u->rc, M, R, pos, val);
//     if(!u->f)
//         u->res = u->lc->res | u->rc->res;
//     else
//         u->res = u->lc->res ^ u->rc->res;

    
// }
// int main() {
//     ios::sync_with_stdio(0), cin.tie(0);
    
//     int n, m, a, b;
//     cin >> n >> m;
//     for(int i = 0; i < 1<<n; ++i)
//         cin >> V[i];
//     node* root = build(0, 1<<n);
//     while(m--) {
//         cin >> a >> b;
//         update(root, 0, 1<<n, a-1, b);
//         cout << root->res << "\n";
//     }
    
//     return 0;
// }