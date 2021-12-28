/*      ###########################
        #  Author : hariom mewada   #
        #  College : SGSITS       #
        ###########################
*/      
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long int 
#define ld long double
#define MOD 1000000007  
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define fo(n) for(int i=0;i<n;i++)
#define rfo(n) for(int i=n-1;i>=0;i--)
const int mod=1e9+7;
const int maxn=2e5+5;

using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;
///typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#ifndef Harry
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
#define ff first
#define ss second
#define set_bits __builtin_popcount

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


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
void cntfact(){
    fact[0]=1;
    for(int i=1;i<=2e5;i++){
        fact[i]=(fact[i-1]*fact[i])%mod;
    }
}
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
int dx=1;
int dy=1;
int call=0;
int helper(int x,int y,int r,int c,int n,int m){
   // if(call>7) return 0;
    //cout<<x<<" "<<y<<endl;
 //   call++;
    if(x==r || y==c) return 0;
    if(x+dx>n) dx=-1;
    if(y+dy>m) dy=-1;
    if(x+dx<1) dx=1;
    if(y+dy<1) dy=1;
    int cnt=0;
    cnt=1+helper(x+dx,y+dy,r,c,n,m);
    return cnt;
}
void solve(){
  int n,m,rb,cb,rd,cd;
  dx=1;
  dy=1;
  cin>>n>>m>>rb>>cb>>rd>>cd;
  int ans=helper(rb,cb,rd,cd,n,m);
  cout<<ans<<endl;   
}
int32_t main(){
	fast_io;
    int t=1;
    cin>>t;
     while(t--){
        solve();
     }
//      #ifndef Harry
//      cerr << "Time Taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
//  #endif
    return 0;
}