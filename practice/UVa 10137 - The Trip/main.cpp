#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int a[1010];
int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int n;

    while(cin >> n) {
        if(n == 0)
            break;
        ld res = 0, val;
        int sum = 0;
        int avg, num;
        int c, d;
        for(int i = 0; i < n; ++i) {
            scanf("%d.%d", &c, &d);
            a[i] = c*100 + d; 
            sum += a[i];
        }      
        avg = sum / n;
        num = sum % n;
        
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] <= avg)
                res += avg-a[i];
            else
                cnt++;
        }
        if(num > cnt)
            res += num-cnt;
        // sort(a, a+n, greater<int>());
        // for(int i = 0; i < num; ++i)
        //     res += abs(a[i] - (avg+1));
        // for(int i = num; i < n; ++i)
        //     res += abs(a[i] - avg);

        printf("$%.2llf\n", res/100);
         
    }
    return 0;
}