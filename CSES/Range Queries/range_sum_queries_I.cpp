#include<bits/stdc++.h>
#define MAX 100
#define MOD 100
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, q;
    cin>>n>>q;
    vector<ll>ar(n + 5);
    cin>>ar[1];
    for(int i = 2; i <= n; i++)
        cin>>ar[i],
        ar[i] += ar[i - 1];
    while(q--){
        ll a, b;
        cin>>a>>b;
        cout<<ar[b] - ar[a - 1]<<"\n";
    }
    
    
}