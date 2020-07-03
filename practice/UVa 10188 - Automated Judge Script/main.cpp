#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, idx = 1;
    string s;

    while(cin >> n) { // read input n
        getline(cin, s);
        if(n == 0) // end of input
            break;
        vector<string> ans(n); // record the correct answer
        vector<char> r1, r2; // record the numeric character for presentation error
        int flag = 1; // record if the submission is Accepted, 1 for Accepted, 2 for the others
        string out = "Accepted"; // output string

        // recrod the answer information
        for(int i = 0; i < n; ++i) {
            getline(cin, ans[i]);
            for(int j = 0; j < ans[i].length(); ++j) {
                if(ans[i][j] >= '0' && ans[i][j] <= '9') {
                    r1.push_back(ans[i][j]);
                }
            }
        }
        cin >> m; // read m input
        getline(cin, s);
        for(int i = 0; i < m; ++i) {
            getline(cin, s);
            // record the numeric in r2 vector
            for(int j = 0; j < s.length(); ++j) {
                if(s[j] >= '0' && s[j] <= '9') {
                    r2.push_back(s[j]);
                }
            }
            if(flag == 1) { // Accept condition
                if(s.length() == ans[i].length() && n == m) {
                    for(int j = 0; j < s.length(); ++j) {
                        if(ans[i][j] != s[j]) { // check if the all of character are the same
                            flag++;
                            break;
                        }
                    }
                }  
                else
                    flag++;
            }
            if(flag == 2) { // the other condition
                out = "Presentation Error";    
                // check if wrong answer or presentation error
                if(i == m-1) {
                    if(r1.size() == r2.size()) {
                        for(int j = 0; j < r1.size(); ++j) {
                            if(r1[j] != r2[j]) { // numeric record is different
                                out = "Wrong Answer";
                            }
                        }
                    }
                    else
                        out = "Wrong Answer";
                }
            }
        }
        // output the result
        cout << "Run #" << idx++ << ": " << out << "\n";
    }
    return 0;
}