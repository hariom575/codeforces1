/*      ###########################
        #  Author : hariom mewada   #
        #  College : SGSITS       #
        ###########################
*/      
#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long int 
const int mod=1e9+7;
const int maxn=2e5+5;
#define MOD 1000000007  
#define endl '\n'
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
using namespace std;
bool prime[100005];
void SieveOfEratosthenes(int n)//O(nloglogn) 
{  
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}  
bool isPrime(int n)//O(sqrt(n))
{
    if(n<2)
        return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}
std::vector<int> factors(int n)//O(sqrt(n))
{
    std::vector<int> f;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            f.push_back(i);
            n = n/i;
        }
    }
    if(n>1) f.push_back(n);
    return f;
}
int gcd(int a,int b)//O(logn)
{
    if(!b) return a;
    return gcd(b,a%b);
}
int eulerstotientfunction(int n)//O(sqrt(n))
{
    int ans = n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n = n/i;
            ans -= ans/i;
        }
    }
    if(n>1)
        ans -= ans/n;
    return ans;
}
using vl=vector<int>;
vl fact(2e5 + 5,1);
int binPow(int a,int b)///binomial power
{
    if (b == 0)return 1;
    if (b == 1)return a;
    int ret = binPow(a,b/2);
    if (b%2 == 0)return (ret * ret)%mod;
    return ((ret * ret)%mod * a)%mod;
}
int inv(int a)////modulo inverse
{
    return (binPow(a,mod - 2)%mod + mod)%mod;
}
int  binom(int a,int b)///ncr
{
    if (b < 0 or a < 0)return 0;
    return (((fact[a] * inv(fact[b]))%mod * inv(fact[a - b]))%mod + mod)%mod;
}
vector<int>dp;
int dfs(int idx,int n,string &s){
    // cout<<idx<<" ";
     if(idx>=n){
        dp[idx]=s[idx]=='?'?2:1;
        return dp[idx];
     }
     int ans=0;
     if(s[idx]=='?') 
      ans=(dfs(2*idx,n,s)+dfs(2*idx+1,n,s));
     else if(s[idx]=='1'){
    ans=dfs(2*idx,n,s);
     }
     else
     ans=dfs(2*idx+1,n,s);
     return dp[idx]=ans;
}
int dfs1(int idx,int n,string &s){
    if(idx>=n){
       if(idx==target)
         return dp[idx];
         else 
        return 0;
    }
    int ans=0;
     if(s[idx]=='?') 
      ans=(dfs(2*idx,n,s)+dfs(2*idx+1,n,s));
     else if(s[idx]=='1'){
    ans=dfs(2*idx,n,s);
     }
     else
     ans=dfs(2*idx+1,n,s);
     return dp[idx]=ans;
}
int32_t main(){
	int t=1;
	fast_io;
///	cin>>t;
	while(t--){
        int k;
        cin>>k;
       string s1;
       cin>>s1;
       int n=(1<<k);
       dp=vector<int>(n+1,0);
       reverse(s1.begin(),s1.end());
       string s="#"+s1;
       dfs(1,n/2,s);
       for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
       int q;
       cin>>q;
       while(q--){
           int p;
           char c;
           cin>>p>>c;
           int ans=dp[1];
           int idx=n-1
           ans-=dp[]
           //cout<<s<<" ";
       }
     }
    
    return 0;
}