#include<bits/stdc++.h>
using namespace std;

struct my_type {
    int val;
    int pos;

    bool operator < (const my_type &B) const {
        return val > B.val; // min heap
    }
};
int main()
{
    int k;
    int L1[800], L2[800];
    while (cin >> k) {
        for (int i = 0; i < k; ++i)
            cin >> L1[i];
        sort(L1, L1 + k);

        for (int j = 0; j < k-1; ++j) {
            for (int i = 0; i < k; ++i)
                cin >> L2[i];
            sort(L2, L2 + k);
            
            priority_queue<my_type> PQ;
            for (int i = 0; i < k; ++i) 
                PQ.push({L1[i] + L2[0], 0});
            
            for (int i = 0; i < k; ++i) {
                my_type tmp = PQ.top();
                PQ.pop();
                L1[i] = tmp.val;
                if (tmp.pos+1 < k)
                    PQ.push({tmp.val - L2[tmp.pos] + L2[tmp.pos+1], tmp.pos + 1});
            }
        }
        for (int i = 0; i < k-1; ++i)
            cout << L1[i] << " ";
        cout << L1[k-1] << '\n';
    }
}