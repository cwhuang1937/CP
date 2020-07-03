#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ll MAX = 1e6 + 1000;
ll dp[MAX] = {0};

int main() {
    // speed up input and output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll a, b;
    while(cin >> a >> b) { // read input range
        ll up, low;
        ll maxc = 0;

        // judge which number is upper or lower
        if(a < b) {
            up = b;
            low = a;
        }
        else {
            up = a;
            low = b;
        }
        // run all of number in this range
        for (ll i = low; i <= up; ++i) {
            ll n = i;
            ll count = 1;
            // run the algorithm by this problem
            while(n != 1) {             
                if(n % 2 == 0)
                    n /= 2;
                else
                    n = 3 * n + 1;

                if(n < MAX && dp[n] != 0) {              
                    count += dp[n];
                    break;
                }    
                count++;       
            }
            dp[i] = count;

            // find the max cycle-length in this range
            maxc = max(maxc, count);
            
        }
        // output the result
        cout << a << " " << b << " " << maxc << "\n";
    }
    return 0;
}