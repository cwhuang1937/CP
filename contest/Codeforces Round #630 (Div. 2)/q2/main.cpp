#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

// bool ismp(int a, int b) {
    
//     if(a == 1 || b == 1)
//         return true;
    
//     while(1) {
//         int t = a%b;
//         if(t == 0)
//             break;
//         else {
//             a = b;
//             b = t;
//         }
//     }
//     if(b > 1)
//         return false;
//     return true;
// }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> V(n);
        int num;
        for(int i = 0; i < n; ++i) {
            cin >> num;
            for(int j = 2; j <= num; ++j) {
                if(num%j == 0) {
                    V[i] = j;
                    break;
                }
            }
        }
        int c[n];
        int color = 1;
        for(int i = 2; i <= 32; ++i) {
            bool f = false;
            for(int j = 0; j < n; ++j) {
                if(V[j] == i) {
                    f = true;
                    c[j] = color;
                }
            }
            if(f)
                color++;
        }
       
        

        cout << *max_element(c, c+n) << "\n";
        for(int i = 0; i < n; ++i)
            cout << c[i] << " ";
        cout << "\n";
        
    }
    return 0;
}