#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
 
int main(){
    
    ll N, X;
    cin>>N>>X;
    ll coins[N];
    for(ll i = 0; i < N; i++)
        cin>>coins[i];
        
    ll memo[X + 1];
    for(ll i = 0; i <= X; i++)
        memo[i] = 0;
        
    memo[0] = 1;
    for(ll d = 1; d <= X; d++)
        for(ll n = 0; n < N; n++)
            if(d - coins[n] >= 0)
                memo[d] = (memo[d] + memo[d  - coins[n]]) % MOD;
    cout<<memo[X];
        
}