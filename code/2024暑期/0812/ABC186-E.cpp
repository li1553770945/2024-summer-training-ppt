#include <iostream>

using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) 
{
    if (b) 
    {
        ll d=exgcd(b, a%b, y, x);
        y-=a/b*x;
        return d;
    } 
    else 
    {
        x=1;
        y=0;
        return a;
    }
}
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main() 
{
    
    int t;
    cin>>t;
    while (t--) 
    {
        ll n,s,k;
        cin>>n>>s>>k;
        s=n-s;
        ll g= gcd(n, k);
        if (s%g!=0) 
        {
            cout<<"-1\n";
            continue;
        }
        ll x,y;
        exgcd(k, n, x, y);
        x *= (s/g);
        y *= (s/g);
        ll mod = n/g;
        x = (x % mod + mod) % mod;
        cout<<x<<"\n";
    }
    return 0;
}