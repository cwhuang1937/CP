#include<bits/stdc++.h>
// #include"lib0020.h"
#define ll long long
#define ld long double
using namespace std;

long long _M, _h;

int _count = 0;

int is_broken(long long k){
	_count++;
	if(_count > 60){
		printf("Wrong Answer: too many queries\n");
		exit(0);
	}
	if(k > _M){
		printf("Wrong Answer: invalid broken query\n");
		exit(0);
	}
	return k > _h;
}

ll height_limit(ll M) {
    ll l = 1;
    ll r = M + 1;
    ll m;

    while(l != r) {        
        m = (l + r) / 2;
        // cout << m << "\n";
        if(!is_broken(m)) {
            l = m + 1;
            // cout << "l: " << l << "\n";
        }
        else {
            r = m;
            // cout << "r: " << r << "\n";
        }

    }
    return r - 1;
}





int main() {
	long long hl, ret;
	ret = scanf("%lld %lld", &_M, &_h);
	hl = height_limit(_M);
    cout << hl << "\n";
	if(hl == _h)
		printf("Accept: query %d times\n", _count);
	else
		printf("Wrong Answer: incorrect height\n");
}
