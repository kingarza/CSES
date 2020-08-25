#include<bits/stdc++.h>
#define MOD 1000000007
#define ll unsigned long long
using namespace std;
 
ll P(ll b, ll e, ll m){
    if(e == 0)
        return 1;
    if(e == 1)
        return b;
    ll ans = P(b, e/2, m) % m;
    ans = (ans * ans) % m;
    if(e % 2 != 0)
        ans = (ans * b) % m;
    return ans % m;
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    while (n--){
        ll a, b, c;
        cin>>a>>b>>c;
        cout<<P(a, P(b, c, MOD - 1), MOD)<<"\n";
    }
    
}
