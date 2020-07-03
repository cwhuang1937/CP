#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int n;
char cm[26];
bool over = 0;
vector<string> dict, text, output, res;

void dfs(int dep) {
    if(over || dep == -1 || dep == text.size()) {
        if(!over) {
            res = output;
        }
        over = 1;
        return;
    }
    for(int i = 0; i < dict.size(); ++i) {      
        if(text[dep].length() == dict[i].length()) {
            
            bool f = 1;
            vector<int> rec;
            for(int j = 0; j < text[dep].length(); ++j) {
                char c = text[dep][j];
                // cout << c << "\n";
                if(cm[c-'a'] == '*') {
                    for(int k = 0; k < 26; ++k) {
                        if(cm[k] == dict[i][j]) {
                            f = 0;
                            break;
                        }
                    }
                    cm[c-'a'] = dict[i][j];
                    rec.push_back(c-'a');
                }
                else {
                    // cout << i << " " <<  j << "\n";
                    // cout << dict[i][j]  << " " << cm[c-'a'] << "\n";
                    if(dict[i][j] != cm[c-'a']) {
                        f = 0;
                        break;
                    }
                }
            }
            if(f) {        
                string out = "";
                for(int j = 0; j < text[dep].length(); j++) {         
                    out += cm[text[dep][j]-'a'];
                }
                output.push_back(out);
                // cout << text[dep] << " to " << out << "\n\n";
                dfs(dep+1);
                output.pop_back();
                for(int k = 0; k < rec.size(); ++k)
                    cm[rec[k]] = '*';
            }
            for(int k = 0; k < rec.size(); ++k)
                cm[rec[k]] = '*';
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string str;
    cin >> n;
    
    for(int i = 0; i < 26; ++i)
        cm[i] = '*';
    for(int i = 0; i < n; ++i) {
        cin >> str;
        dict.push_back(str);
    }
    getline(cin, str);

    while(getline(cin, str)) {
        stringstream ss(str);
        while(ss >> str) {
            text.push_back(str);
        }
        dfs(0);
        if(res.size() == text.size()) {
            for(int i = 0; i < res.size()-1; ++i)
                cout << res[i] << " ";
            cout << res[res.size()-1] << "\n";
        }
        else {
            for(int i = 0; i < text.size(); ++i) {
                for(int j = 0; j < text[i].length(); ++j) {
                    cout << "*";
                }
                if(i != text.size()-1)
                    cout << " ";
            }
            cout << "\n";
        }
        text.clear();
        output.clear();
        res.clear();
        over = 0;
        for(int i = 0; i < 26; ++i)
            cm[i] = '*';
    }


    return 0;
}