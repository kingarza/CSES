#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
vector<ll>ar;

ll f(ll x){
    ll suma = 0;
    for(auto i : ar)
        suma += abs(i - x);
    return suma;
}

ll ternary_search(ll l, ll r){
    for(int i = 1; i <= 200; i++){
        ll a = l + (r - l) / 3,
           b = r - (r - l) / 3;
        if(f(a) < f(b))
            r = b;
        else
            l = a;
    }
    //el for le da una mayor precisión al resultado, nos queda un rango pequeño para calcular
    ll Min = LLONG_MAX;
    while(l <= r)
        Min = min(Min, f(l++));
    return Min;
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>n;
    for(ll i = 0, x; i < n; i++)
        cin>>x, ar.push_back(x);     
    cout<<ternary_search(0, 1000000000);
}