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
int32_t main(){
	int t=1;
	fast_io;
	cin>>t;
	while(t--){
    int n,m;
    cin>>n>>m;
   // cout<<n<<m;
    vector<int>a(n);
    vector<int>b(n);
    vector<int>c(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int j=0;j<m;j++) cin>>c[j];
    vector<vector<int>>req(n+1);
    vector<int>ans(m);
    vector<int>vis(n+1,0);
    vector<int>final=a;
    vector<int>index(n+1);
    for(int i=0;i<n;i++){
        vis[b[i]]=1;
        index[b[i]]=i;
    }
    int last=-1;
    for(int j=m-1;j>=0;j--){
        if(vis[c[j]]){
            last=j;
            break;
        }
    }
    for(int i=0;i<n;i++){
       /// cout<<a[i]<<b[i]<<" ";
        if(b[i]!=a[i])
      req[b[i]].push_back(i);
    }
    bool h=false;
    for(int i=0;i<m;i++){
        if(req[c[i]].size()>0){
            int idx=req[c[i]].back();
            req[c[i]].pop_back();
            ans[i]=idx;
        }else if(vis[c[i]]){
            ans[i]=index[c[i]];
        }
        else  if(i<=last){
            ans[i]=index[c[last]];
        }else{
            h=true;
        }
    }
    if(h) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<m;i++)
        cout<<ans[i]+1<<" ";
        cout<<endl;
    }
     }
    
    return 0;
}