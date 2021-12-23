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
int par[1005];
int sz[1005];
int vis[1005];
int cur=0;
int find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void Union(int x,int y){
int a=find(x);
int b=find(b);
if(a==b) return ;
if(sz[a]>sz[b])
swap(a,b);
sz[b]+=sz[a];
par[a]=b;
}
int32_t main(){
	int t=1;
	fast_io;
	///cin>>t;
	while(t--){
      int n,m;
      cin>>n>>m;
      vector<pair<int,int>>p;
      for(int i=0;i<m;i++){
          int u,v;
          cin>>u>>v;
          p.push_back({u,v});
      }
      for(int i=0;i<m;i++){
          for(int i=0;i<=n;i++){
              par[i]=i;
              sz[i]=1;
              vis[i]=false;
          }
          int e=0;
          for(int j=0;j<=i;j++){
                 if(find(p[i].first)==find(p[i].second))
                 {e++; continue;}
                 Union(p[i].first,p[i].second);
          }
          vector<int>lol;
          for(int i=1;i<=n;i++){
              if(!vis[i]){
                  cur=0;
                  dfs(i);
                  lol.push_back(cur);
              }
          }
          sort(begin(lol),end(lol),greater<int>());
          int ans=lol[0]-1;
          for(int j=1;j<lol.size();j++){
              if(e<=0) break;
              ans+=lol[i];
          }
          cout<<ans<<endl;
      }
     }
    
    return 0;
}