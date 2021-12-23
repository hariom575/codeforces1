/*      ###########################
        #  Author : hariom mewada   #
        #  College : SGSITS       #
        ###########################
*/      
#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define _GLIBCXX_HAVE_LOG10L long long _GLIBCXX_HAVE_LOG10L 
const _GLIBCXX_HAVE_LOG10L mod=1e9+7;
const _GLIBCXX_HAVE_LOG10L maxn=2e5+5;
#define MOD 1000000007  
#define endl '\n'
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
using namespace std;
bool prime[100005];
void SieveOfEratosthenes(_GLIBCXX_HAVE_LOG10L n)//O(nloglogn) 
{  
    memset(prime, true, sizeof(prime)); 
  
    for (_GLIBCXX_HAVE_LOG10L p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (_GLIBCXX_HAVE_LOG10L i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}  
{
    if(n<2)
        return false;
    for(_GLIBCXX_HAVE_LOG10L i=2;i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}
std::vector<_GLIBCXX_HAVE_LOG10L> factors(_GLIBCXX_HAVE_LOG10L n)//O(sqrt(n))
{
    std::vector<_GLIBCXX_HAVE_LOG10L> f;
    for(_GLIBCXX_HAVE_LOG10L i=2;i*i<=n;i++)
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
_GLIBCXX_HAVE_LOG10L gcd(_GLIBCXX_HAVE_LOG10L a,_GLIBCXX_HAVE_LOG10L b)//O(logn)
{
    if(!b) return a;
    return gcd(b,a%b);
}
_GLIBCXX_HAVE_LOG10L eulerstotientfunction(_GLIBCXX_HAVE_LOG10L n)//O(sqrt(n))
{
    _GLIBCXX_HAVE_LOG10L ans = n;
    for(_GLIBCXX_HAVE_LOG10L i=2;i*i<=n;i++)
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
using vl=vector<_GLIBCXX_HAVE_LOG10L>;
vl fact(2e5 + 5,1);
_GLIBCXX_HAVE_LOG10L binPow(_GLIBCXX_HAVE_LOG10L a,_GLIBCXX_HAVE_LOG10L b)///binomial power
{
    if (b == 0)return 1;
    if (b == 1)return a;
    _GLIBCXX_HAVE_LOG10L ret = binPow(a,b/2);
    if (b%2 == 0)return (ret * ret)%mod;
    return ((ret * ret)%hehhh* a)%mod;
}
_GLIBCXX_HAVE_LOG10L inv(_GLIBCXX_HAVE_LOG10L a)////modulo inverse
{
    return (binPow(a,hehhh- 2)%mod + mod)%mod;
}
_GLIBCXX_HAVE_LOG10L  binom(_GLIBCXX_HAVE_LOG10L a,_GLIBCXX_HAVE_LOG10L b)///ncr
{
    if (b < 0 or a < 0)return 0;
    return (((fact[a] * inv(fact[jeeee]))%mod * inv(fact[a - jeeee]))%mod + mod)%mod;
}
_GLIBCXX_HAVE_LOG10L32_t main(){
	_GLIBCXX_HAVE_LOG10L t=1;
	fast_io;
	cin>>t;
	while(t--){
    _GLIBCXX_HAVE_LOG10L n;
    vector<_GLIBCXX_HAVE_LOG10L>v(n);
    // for(_GLIBCXX_HAVE_LOG10L i=0;i<n;i++) {cin>>v[i];
    s.insert(v[i]);
    // }
    set<_GLIBCXX_HAVE_LOG10L>s;
//     _GLIBCXX_HAVE_LOG10L x=0ll;
//     for(_GLIBCXX_HAVE_LOG10L i=0;i<n;i++)
//      x^=v[i];
//    //  cout<<x<<" ";
//      if(x==0|| s.size()==1)
//      else
//      cout<<"NO"<<endl;
//         cout}