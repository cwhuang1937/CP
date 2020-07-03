#include<bits/stdc++.h>
using namespace std;

int n;
void printout(vector<char> v, char c, int letters) {
    v.push_back(c);
    if(v.size() == n) {
        for (int i = 0; i < n; ++i)
            cout << v[i];
        cout << '\n';
    }
    else {
        for (int i = 0; i <= letters; ++i) {
            if(i == letters)
                printout(v, 'a' + i, letters + 1);
            else
                printout(v, 'a' + i, letters);
        } 
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    vector<char> v;
    cin >> n;

    printout(v, 'a', 1);
    return 0;
}