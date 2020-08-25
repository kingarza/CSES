#include <iostream>
#define ll unsigned long long
#define MOD 1000000007
using namespace std;
 
ll Pow(ll b, ll e){
    if(!e)
        return 1;
    if(e == 1)
        return b;
    ll ans = Pow(b, e / 2) % MOD;
    ans = (ans * ans) % MOD;
    if(e % 2 != 0)
        ans = (ans * b) % MOD;
    return ans % MOD;
}
 
int main() {
	ll n;
	cin>>n;
	cout<<Pow(2, n) % MOD;	
}