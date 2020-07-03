#include<bits/stdc++.h>
using namespace std;

int main() {
    while(1) {
        int n;
        cin >> n;
        if(n == 0)
            break;

        while(1) {
            int in;
            cin >> in;
            if(in == 0){
                cout << '\n';
                break;
            }
                
            
            vector<int> vec;
            stack<int> st;
            
            vec.push_back(in);
            for(int i = 0; i < n-1; ++i) {
                cin >> in;
                vec.push_back(in);
            }
            int index = n;
            while(1) {
                if(!st.empty() && st.top() == index) {
                    // cout << st.top() << '\n';
                    st.pop();
                    index--;
                }
                else if(!vec.empty()) {
                    st.push(vec.back());
                    vec.pop_back();
                }
                else
                    break;
            }

            if(st.empty())
                cout << "Yes\n";
            else
                cout << "No\n"; 

        }



        
    }
    return 0;
}