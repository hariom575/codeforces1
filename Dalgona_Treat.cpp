#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define INF               923456789987654322
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
ll msb(ll N){return(64-__builtin_clzll(N)-1);} 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
ll mod_sub(ll a,ll b,ll m){return(((a%m-b%m+m)%m));}
vector<vector<ll>> adj(2e5+100);
vector<bool> vis(2e5+100,0);
vector<ll> dis(2e5+100,0);
ll MOD=1e9+7;
ll lcm(ll a,ll b){
  ll val=__gcd(a,b);
  return((a*b)/val);
}
vector<ll> dp(1e5+5,0);
void Jai_shree_ganesh(ll tt){
//cout<<"never give up"<<endl;
//cout<<"play to win"<<endl;
//cout<<"Case #"<<tt<<": ";
ll N,k;
cin>>N>>k;
vector<ll> v(N);
ll sum=0;
for(ll i=0;i<N;i++){
cin>>v[i];
sum+=v[i];
}
if(sum<k){
    cout<<0<<"\n";
    return;
}
vector<vector<ll>> dp(N+5,vector<ll>(k+5,0));
dp[N][0]=1;
for(ll i=0;i<=N;i++) dp[i][0]=1;
for(ll i=N-1;i>=0;i--){
for(ll j=1;j<=k;j++){
    if((j-v[i]-1)>=0)
    dp[i][j]=(dp[i+1][j]%MOD-dp[i+1][(j-v[i]-1)]+MOD)%MOD;
    else{
        dp[i][j]=(dp[i+1][j]%MOD);
    }
}
 for(ll ii=1;ii<=k;ii++){
     dp[i][ii]=(dp[i][ii]%MOD+dp[i][ii-1]%MOD)%MOD;
    }
}
//debug(dp)
cout<<dp[0][k]%MOD<<"\n";
} 
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    freopen("Error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    for(ll i=1;i<1e5+5;i++){
        dp[i]=(i*(i+1))/2;
    }
   // for(ll i=1;i<=1e5;i++) dp[i]+=dp[i-1];
    for(ll i=1;i<=t;i++)
    {
    Jai_shree_ganesh(t); 
    }
    return(0);
}