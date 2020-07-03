#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct edge {
    int u, v;
    double w;
};
struct point {
    int x, y;
};

int g[5010];
point PS[5010];
vector<edge> E;

int Find(int a) {
    if(a == g[a])
        return a;
    return g[a] = Find(g[a]);
}
void Union(int a, int b) {
    g[Find(a)] = Find(b);
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, S, P, x, y;
    cin >> N;

    while(N--) {
        int cnt = 0;
        double w, res = 0;
        E.clear();
        cin >> S >> P;
        for(int i = 0; i < P; ++i) {
            cin >> x >> y;
            PS[i] = {x, y};
            g[i] = i;
        }
        
        for(int i = 0; i < P-1; ++i) {
            for(int j = i+1; j < P; ++j) {
                double dx = PS[i].x - PS[j].x;
                double dy = PS[i].y - PS[j].y;
                w = sqrt(dx*dx + dy*dy);
                E.push_back({i, j, w});
            }
        }
        sort(E.begin(), E.end(), [](edge A, edge B) { return A.w < B.w;});

        for(auto e : E) {
            if(Find(e.u) != Find(e.v)) {
                Union(e.u, e.v);
                cnt++;
                if(cnt + S - 1 == P-1) {
                    res = e.w;
                    break;
                }
            }
        }
        printf("%.2lf\n", res);
        

    }
    return 0;
}