#include<bits/stdc++.h>
#include "lib0043.h"
#define ll long long
#define ld long double
using namespace std;

deque<int> q1, q2;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
	int N;
	MagicBalls(&N);
    // cin >> N;
    // for(int i = 1; i <= N; ++i)
    //     cin >> a[i];
    // cout << N << "\n";

    
    for(int i = 1; i < N; i+=2) {
        if(Collision(i, i+1)) {
            q1.push_back(i);
            q2.push_back(i+1);
        }
        else {
            q2.push_back(i);
            q1.push_back(i+1);
        }
    }
    
    while(q1.size() != 1) {
        int t1 = q1.front();
        int t2 = q1.back();
        
        if(Collision(t1, t2)) {
            q1.pop_back();
        }
        else {
            q1.pop_front();
        }
    }
    while(q2.size() != 1) {
        int t1 = q2.front();
        int t2 = q2.back();
        
        if(Collision(t1, t2)) {
            q2.pop_front();
        }
        else {
            q2.pop_back();
        }
    }
    int mx = q1.front();
    int mi = q2.front();
    if(N % 2 == 1) {
        if(!Collision(mx, N)) {
            mx = N;
        }
        else {
            if(Collision(mi, N))
                mi = N;
        }

    }
 
    // cout << mx << " " << mi << "\n";
    Choose(mi, mx);

    return 0;
}