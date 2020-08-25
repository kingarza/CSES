#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
 
ll P(ll b, ll e){
    if(!e)
        return 1;
    if(e == 1)
        return b;
    ll ans = P(b, e / 2);
    ans = (ans * ans) % MOD;
    if(e % 2 != 0)
        ans = (ans * b) % MOD;
    return ans;
}
 
int main(){
    int N;
    cin>>N;
    ll b, e;
    while(N--)
        cin>>b>>e,
        cout<<P(b, e)<<"\n";
}
