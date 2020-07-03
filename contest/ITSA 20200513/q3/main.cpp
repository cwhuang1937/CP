#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    double H, U, D, F;
    while(n--) {
        cin >> H >> U >> D >> F;  
        // if(U >= H) {
        //     cout << ((U/H)*100+5)/100 << "\n";
        //     continue;
        // }
        double diff = H-U;
        double res = 1;
        while(1) {
            // cout << diff << "??\n";
            U = U*(1-F/100);
            // cout << U << "\n";
            res += 1;
            if(diff > U) {
                res += 0.5;
                diff -= U-D;
                if(res >= 10000) {
                    res = 0;
                    break;
                }    
            }
            else {
                break;
            }
        }
        printf("%.1lf\n", res);
    }
    return 0;
}