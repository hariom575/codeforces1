#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define vv vector
#define pb push_back
#define ll long long
#define infi INT_MAX
#define sz size()
#define ss second
#define ii pair
#define ff first
const ll inf=1e9+7;
const ll MOD=998244353;
#define id double
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i=a; i<b; i++)
#define lsd(x) builtin_ffs(x)
#define msd(x) builtin_clz(x)
#define ctz(x) builtin_ctz(x)
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<endl;
#else
#define debug(x)
#endif
void _print(int a){
 cerr<<a;
}
void _print(long long a){
 cerr<<a;
}
void _print(char a){
 cerr<<a;
}
void _print(string a){
 cerr<<a;
}
void _print(bool a){
 cerr<<a;
}
template<class T> void _print(vector<T> v){
 cerr<<"[";
 for(T i: v){
  _print(i);
  cerr<<" ";
 }
 cerr<<"]";
}
template<class T> void _print(set<T> s){
 cerr<<"[";
 for(T i: s){
  _print(i);
  cerr<<" ";
 }
 cerr<<"]";
}
template<typename T> void max_self(T &a, T b){
 a=max(a, b);
}

template<typename T> void min_self(T &a, T b){
 a=min(a, b);
}
ll power(ll a, ll b, ll mod){
 if(b==0) return 1;
 ll ans=power(a,b/2, mod);
 ans *=ans;
 ans %=mod;
 if(b%2) return ans *=a;
 return ans%mod;
 
}
int g(int x, int file[], int n){
 int work=1;
 int load=0;
 rep(i,0,n){
  if((load+file[i])<=x){
   load +=file[i];
  }else{
   work++;
   load=file[i];
  }
 }
 return work;
}
bool p(int x, int file[], int n, int m){
 return g(x, file, n)<=m;
}

const int N=2005;
int dp[N][2];
bool che(int a, int b) {
    if (a == 0) return false;
    if (dp[a][b] != -1)
        return dp[a][b];
    bool ans = false;
    if (a>= 1) ans |= !che(a - 1, !b);
    if (a>= 2) ans |= !che(a - 2, !b);
    return dp[a][b] = ans;
}

void solve(){

    int n, cnt = 0;
    string s; cin >> n >> s;
    rep(i, 0, n+1) dp[i][0] = dp[i][1] = -1;
    rep(i,0,n) cnt += (s[i] == s[i + 1]);
   
     cout<<(che(cnt, 0) ? "JJ" : "Uttu")<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(0);
//  #ifndef ONLINE_JUDGE
//  freopen("Error.txt","w",stderr);
//  #endif
  int t;
  cin>>t;
  while(t--){
  
solve();
}
}