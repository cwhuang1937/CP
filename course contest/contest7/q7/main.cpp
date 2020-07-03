#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll A[100005];

struct node {
  int sum;
  node *lc, *rc; // left child, right child
  node() { sum = 0; lc = rc = NULL; }
};

node* build(int L, int R) {
  node* u = new node();
  if(R-L == 1) { 
    u->sum = A[L];
  } else {
    int M = (L+R) / 2;
    u->lc = build(L, M); // 左子樹
    u->rc = build(M, R); // 右子樹
    
    u->sum = u->lc->sum ^ u->rc->sum;
  }
  
  return u;
}
int query(node* u, int L, int R, int qL, int qR) {
  if(R <= qL || qR <= L) return 0;
  if(qL <= L && R <= qR) return u->sum;
  
  int M = (L+R) / 2;
  return query(u->lc, L, M, qL, qR) ^ query(u->rc, M, R, qL, qR);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, a, b, val;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    node *root = build(1, n+1);
    while(m--) {
        cin >> a >> b;
        cout << query(root, 1, n+1, a, b+1) << "\n";
    }
    return 0;
}

