#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    vector<string> V;
    while(getline(cin, s)) {
        if(s[s.length()-1] == '\r')
            s = s.substr(0, s.length()-1);
        V.push_back(s);
    }
    bool f = 0;
    s = "";
    for(int i = 0; i < V.size(); ++i) {
        if(V[i] == "" && !f) {
            cout << "\n";
            f = 1;
        }
        else if(V[i] == "" && f) {
            while(1) {
                if(s.length() <= 73)
                    break;
                int len = 72;
                while(1) {
                    if(s[len] == ' ' || len == 0)
                        break;
                    len--;
                }
                if(len != 0)
                    cout << s.substr(0, len) << "\n";
                else {
                    len = 72;
                    while(1) {
                        if(s[len] == ' ')
                            break;
                        len++;
                    }
                    cout << s.substr(0, len) << "\n";
                }
                s = s.substr(len+1, s.length()-len);   
            }
            cout << s.substr(0, s.length()-1) << "\n\n";
            s = "";
        }
        else if(f && V[i] != "") {
            s += V[i] + " ";
        }
        else {
            cout << V[i] << "\n";
        }
    }
    while(1) {
        if(s.length() <= 73)
            break;
        int len = 72;
        while(1) {
            if(s[len] == ' ' || len == 0)
                break;
            len--;
        }
        if(len != 0)
            cout << s.substr(0, len) << "\n";
        else {
            len = 72;
            while(1) {
                if(s[len] == ' ')
                    break;
                len++;
            }
            cout << s.substr(0, len) << "\n";
        }
        s = s.substr(len+1, s.length()-len);   
    }
    cout << s.substr(0, s.length()-1);

    return 0;
}