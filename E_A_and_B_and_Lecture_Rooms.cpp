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
vector<int>graph[100001];
int UP[100001][18];
vector<int>depth;
vector<int>sz;
void dfs(int node,int par){
    sz[node]=1;
for(int child:graph[node]){
    if(child==par) continue;
    depth[child]=depth[node]+1;
    UP[child][0]=node;
    for(int j=1;j<18;j++){
        UP[child][j]=UP[UP[child][j-1]][j-1];
    }
    dfs(child,node);
    sz[node]+=sz[child];
}
}
int lca(int x,int y){
    if(depth[x]<depth[y]) swap(x,y);
    int k=depth[x]-depth[y];
    for(int j=17;j>=0;j--){
        if(1&(k>>j)) x=UP[x][j];
    }
    if(x==y) return x;
    for(int j=17;j>=0;j--){
        if(UP[x][j]!=UP[y][j]){
            x=UP[x][j];
            y=UP[y][j];
        }
    }
    return UP[x][0];
}
int getKthAncestor(int node,int k){
    if(depth[node]<k) return node;
    for(int j=0;j<18;j++){
        if(1&(k>>j))
        node=UP[node][j];
    }
    return node;
}
int32_t main(){
	int t=1;
	fast_io;
//	cin>>t;
	while(t--){
        int n;
        cin>>n;
        depth.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1,-1);
        int q;
        cin>>q;
        while(q--){
            int u,v;
            cin>>u>>v;
            int l=lca(u,v);
            int d=depth[u]-depth[l]+depth[v]-depth[l];
            if(d%2)
            {
                cout<<0<<endl;
                continue;
            }
            else if(u==v){
                cout<<n<<endl;
                continue;
            }
            else if((depth[u]-depth[l])==depth[v]-depth[l]){
                cout<<n-sz[u]-sz[v]<<endl;
            }
            else{
             //   cout<<l;
                if(depth[v]>depth[u]) swap(u,v);
                int d1=(d)/2;
                int d2=d/2-1;
                int p1=getKthAncestor(u,d1);
                int p2=getKthAncestor(u,d2);
                cout<<sz[p1]-sz[p2]<<endl;
            }
        //  cout<<l;
        }
     }
    
    return 0;
}