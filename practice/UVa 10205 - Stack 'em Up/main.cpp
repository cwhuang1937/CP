#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int t, n;
    string s;
    cin >> t;
    for(int k = 0; k < t; ++k) {
        if(k != 0)
            cout << "\n";
        vector<int> card(52);
        for(int i = 0; i < 52; ++i)
            card[i] = i;
        cin >> n;
        int rec[n][52];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 52; ++j)
                cin >> rec[i][j];
        getline(cin, s);
        while(getline(cin, s)) {
            if(s == "\r" || s == "")
                break;
            stringstream ss(s);
            vector<int> temp;
            temp = card;
            int num, pos;
            ss >> num;
            for(int i = 0; i < 52; ++i) {
                pos = rec[num-1][i];
                card[i] = temp[pos-1];
            }          
        }
        int value, suit;
        string val, su;
        for(auto i : card) {
            value = i%13;
            suit = i/13;
            // cout << i << "\n";
            if(value == 9)
                val = "Jack";
            else if(value == 10)
                val = "Queen";
            else if(value == 11)
                val = "King";
            else if(value == 12)
                val = "Ace";
            else
                val = to_string(value+2);

            if(suit == 0)
                su = "Clubs";
            else if(suit == 1)
                su = "Diamonds";
            else if(suit == 2)
                su = "Hearts";
            else
                su = "Spades";
            
            cout << val << " of " << su <<"\n";
        }
    }
    return 0;
}