#include<bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> v1, v2;

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v1.push_back(num);
        v2.push_back(num);
    }

    long long sum = 0;
    long long rec;
    sort(v1.begin(), v1.end(), greater<int>());
    for(int i = 0; i < m*k; i++) {
        sum += v1[i];
        if(i == m*k-1)
            rec = v1[i];
    }
        
    cout << sum << '\n';

    int count = 0;
    int cut = 0;

    for(int i = 0; i < n; i++) {
        if(v2[i] >= rec) {
            count++;
        }
        if(count == m) {
            cout << i + 1 << " ";
            count = 0;
            cut++;
        }
        if(cut == k-1) {
            cout << '\n';
            break;
        }
    }


    return 0;
}