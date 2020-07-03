#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
int arr[500005];
int ans[10];
int num;
void dfs(int index,int r){
    if(index == 3){
        for(int i=0;i<3;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        return;
    }
    if(r == num)
        return;
    for(int i=r;i<num;i++){
        if(index != 0){
            if(ans[index-1] > arr[i]){
                ans[index] = arr[i];
                dfs(index+1,i+1);
            }
            else 
                continue;
        }
        else{
            ans[index] = arr[i];
            dfs(index+1,i+1);
        }
    }


}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    dfs(0,0);
    return 0;
}