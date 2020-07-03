#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    while(cin >> n) {
        vector<int> V1(n); // store the n numbers
        vector<bool> V2(n+1, 0); // record the difference between two numbers
        bool f = 0;
        for(int i = 0; i < n; ++i) // read the input
            cin >> V1[i];
        for(int i = 0; i < n-1; ++i) {
            int diff =  abs(V1[i+1] - V1[i]); // use abs() to calculate the difference
            if(diff < 1 || diff > n-1 || V2[diff]) { // the condition of not jolly
                cout << "Not jolly\n";
                f = 1;  // set a flag to avoid printint the jolly
                break;
            }
            V2[diff] = 1;
        }
        if(!f)
            cout << "Jolly\n";
    }
    return 0;
}