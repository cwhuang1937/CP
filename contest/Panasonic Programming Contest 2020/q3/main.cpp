#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b, c;
    cin >> a >> b >> c;

    if(4*a*b < (c-a-b)*(c-a-b)) {
        if(c-a-b <= 0)
            cout << "No\n";
        else
        {
            cout << "Yes\n";
        }
        
    }
        
    else
        cout << "No\n";

    
    return 0;
}