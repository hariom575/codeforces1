#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
const int p = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    int sum = n*(n+1)/2;
    if(sum&1){
        cout<<"0\n";
        return;
    }
    sum/=2;
    vector<int> dp(sum+1);
    dp[0] = (p+1)/2; //(1/2) in mod p
    for(int i=1;i<=n;i++){
        for(int j=sum;j>=i;--j){
            dp[j]+=dp[j-i];
            dp[j] >= p ? dp[j]-=p : 0;
        }
    } 
    cout<<dp[sum]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}