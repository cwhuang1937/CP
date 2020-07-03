#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> V;

    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        V.push_back(num);
    }

    int total = 0;
    for(int i = 0; i < n-2; ++i) {
        int minn = 1e9;
        int index;
        for(int j = 0; j < V.size()-2; ++j) {
            if(V[j] * V[j+2] < minn) {
                index = j;
                minn = V[j] * V[j+2];
            }
        }
        // cout << index << "\n";
        total += V[index] * V[index+1] * V[index+2];
        V.erase(V.begin() + index + 1);
    }
    cout << total << "\n";
    return 0;
}