#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    

    while(getline(cin, s)) {
        list<char> vec;
        list<char>::iterator it = vec.begin();

        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '[') {
                it = vec.begin();
            }
            else if(s[i] == ']') {
                it = vec.end();
            }
            else{
                it = vec.insert(it, s[i]);
                it++;
            }
        }
        for(it = vec.begin(); it != vec.end(); ++it) {
            cout << *it;
        }
        cout << '\n';
    }

    return 0;
}