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
int par1[1002];
int par2[1002];
int find1(int x){
    if(par1[x]==x) return x;
    return par1[x]=find1(par1[x]);
}
int find2(int x){
    if(par2[x]==x) return x;
    return par2[x]=find2(par2[x]);
}
int32_t main(){
	int t=1;
	fast_io;
	//cin>>t;
	while(t--){
    int n,m1,m2;
    cin>>n>>m1>>m2;
    for(int i=1;i<=n;i++){
        par1[i]=i;
        par2[i]=i;
    }
    for(int i=1;i<=m1;i++){
        int u,v;
        cin>>u>>v;
        int x=find1(u);
        int y=find1(v);
        par1[x]=y;
    }
    for(int i=1;i<=m2;i++){
        int u,v;
        cin>>u>>v;
        int x=find2(u);
        int y=find2(v);
        par2[x]=y;
    }
      int cnt=0;
      vector<pair<int,int>>ans;
      for(int i=1;i<=n;i++){
          for(int j=i+1;j<=n;j++){
              int x=find1(i);
              int y=find1(j);
              int a=find2(i);
              int b=find2(j);
              if(x!=y and  b!=a)
              {
                 // cout<<i<<j<<endl;
                 ans.push_back({i,j});
                  par1[x]=y;
                  par2[a]=b;
              }
          }
      }
     cout<<ans.size()<<endl;
     for(auto a:ans)
     cout<<a.first<<" "<<a.second<<endl;
     }
    
    return 0;
}